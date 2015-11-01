#include "sqlite3Appender.h"
#include "sqlite3.h"
#include "xtext.h"
#include "log.h"
#include "level.h"

#include <iostream>
using namespace std;

string g_LastSqlite3Error("NoError");

#define RESET_LAST_ERR g_LastSqlite3Error = "NoError";
#define SET_LAST_ERR(err) g_LastSqlite3Error = err;
#define LOG_TABLE "LogTable"

DGR2_NP_BEGIN
struct Sqlite3Appender::Impl
{
    Impl(const std::xStrT& db_file);
    bool checkIfTableExists(const string& table)const;
    void createLogTableIfNecessary();
    bool executeNonQuerySql(const char* sql);
    ~Impl();
    xStrT db_file_;
    sqlite3* db_conn_;
};

Sqlite3Appender::Impl::Impl(const std::xStrT& db_file)
    :db_file_(db_file),
    db_conn_(NULL)
{
}

Sqlite3Appender::Impl::~Impl()
{    
}

bool Sqlite3Appender::Impl::checkIfTableExists(const string& table) const
{    
    sqlite3_stmt* st = NULL;
    int result = sqlite3_prepare_v2(db_conn_, "SELECT name FROM sqlite_master WHERE type='table';", -1, &st, NULL);
    if (result != SQLITE_OK)
    {
        SET_LAST_ERR(sqlite3_errmsg(db_conn_));        
        return false;
    }
    bool is_match = false;
    while ((result = sqlite3_step(st)) == SQLITE_ROW)
    {
        const char* column_name = reinterpret_cast<const char*>(sqlite3_column_text(st, 0));
        if (table == column_name)
        {
            is_match = true;
            break;
        }
    }
    sqlite3_finalize(st);
    return is_match;
}

void Sqlite3Appender::Impl::createLogTableIfNecessary()
{
    if (checkIfTableExists(LOG_TABLE))
        return;
    sqlite3_stmt* st = NULL;
    char create_table_sql_buffer[300] = { '\0' };
    sprintf_s(create_table_sql_buffer,
                     300,
                     "CREATE TABLE %s(id INTEGER PRIMARY KEY AUTOINCREMENT,"
                                                              "level CHAR(30) NOT NULL, "
                                                              "logger CHAR(30) NOT NULL,"
                                                              "func CHAR(50) NOT NULL, "
                                                              "file CHAR(50) NOT NULL, "
                                                              "lineno INT NOT NULL, "
                                                              "thread_id INT NOT NULL, "
                                                              "timestamp TEXT NOT NULL,"
                                                              "content TEXT NOT NULL);",
                     LOG_TABLE);
    sqlite3_prepare_v2(db_conn_, create_table_sql_buffer, -1, &st, NULL);        
    if(sqlite3_step(st) != SQLITE_DONE)
    {
        SET_LAST_ERR(sqlite3_errmsg(db_conn_));
        return;
    }
    sqlite3_finalize(st);
}

bool Sqlite3Appender::Impl::executeNonQuerySql(const char* sql)
{
    sqlite3_stmt* st = NULL;
    sqlite3_prepare_v2(db_conn_, sql, -1, &st, NULL);
    if (sqlite3_step(st) != SQLITE_DONE)
    {
        SET_LAST_ERR(sqlite3_errmsg(db_conn_));
        sqlite3_finalize(st);
        return false;
    }
    sqlite3_finalize(st);
    return true;
}

bool Sqlite3Appender::open()
{
    RESET_LAST_ERR;
    if (impl_->db_conn_ != NULL)
        return true;
    char* utf8_str = NULL;
    WideCharToUtf8(impl_->db_file_.c_str(), utf8_str);
    int result = sqlite3_open_v2(utf8_str, &impl_->db_conn_, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
    delete[] utf8_str;
    if (result != SQLITE_OK)
    {        
        SET_LAST_ERR(sqlite3_errmsg(impl_->db_conn_));
        sqlite3_close_v2(impl_->db_conn_);
        return false;
    }
    impl_->createLogTableIfNecessary();
    return true;
}

void Sqlite3Appender::close()
{
    RESET_LAST_ERR;
    if (impl_->db_conn_)
        sqlite3_close_v2(impl_->db_conn_);
    impl_->db_conn_ = NULL;
}

Sqlite3Appender::Sqlite3Appender(const std::xStrT& db_file, unsigned int flush_frequence)
    :DefAppender(flush_frequence),
    impl_(new Impl(db_file))
{
}

Sqlite3Appender::~Sqlite3Appender()
{
    close();
    delete impl_;
    impl_ = NULL;
}

void Sqlite3Appender::write(const Log& log, const std::xStrT& logged_msg)
{
    RESET_LAST_ERR;
    if (!impl_->executeNonQuerySql("BEGIN;"))    
        return;    
    char insert_record_sql_buffer[200] = { '\0' };
    sprintf_s(insert_record_sql_buffer, "INSERT INTO %s(level, logger, func, file, lineno, thread_id, timestamp, content) VALUES(?1, ?2, ?3, ?4, ?5, ?6, ?7, ?8);", LOG_TABLE);
    sqlite3_stmt* st = NULL;    
    sqlite3_prepare_v2(impl_->db_conn_, insert_record_sql_buffer, -1, &st, NULL);
    char* utf8_buffer_arry[6] = { NULL };    
    WideCharToUtf8(log.level_->repr(), utf8_buffer_arry[0]);
    sqlite3_bind_text(st, 1, utf8_buffer_arry[0], -1, SQLITE_STATIC);    
    WideCharToUtf8(log.func_name_.c_str(), utf8_buffer_arry[1]);
    sqlite3_bind_text(st, 2, utf8_buffer_arry[1], -1, SQLITE_STATIC);    
    WideCharToUtf8(log.func_name_.c_str(), utf8_buffer_arry[2]);
    sqlite3_bind_text(st, 3, utf8_buffer_arry[2], -1, SQLITE_STATIC);    
    WideCharToUtf8(log.filename_.c_str(), utf8_buffer_arry[3]);
    sqlite3_bind_text(st, 4, utf8_buffer_arry[3], -1, SQLITE_STATIC);
    sqlite3_bind_int(st, 5, log.lineno_);
    sqlite3_bind_int(st, 6, log.thread_id_);    
    WideCharToUtf8(log.timestamp_.repr().c_str(), utf8_buffer_arry[4]);
    sqlite3_bind_text(st, 7, utf8_buffer_arry[4], -1, SQLITE_STATIC);
    char* utf8_level_buffer = NULL;
    WideCharToUtf8(log.content_.c_str(), utf8_buffer_arry[5]);
    sqlite3_bind_text(st, 8, utf8_buffer_arry[5], -1, SQLITE_STATIC);    
    if (sqlite3_step(st) != SQLITE_DONE)    
        SET_LAST_ERR(sqlite3_errmsg(impl_->db_conn_));    
    sqlite3_finalize(st);
    for (int i = 0; i < sizeof(utf8_buffer_arry) / sizeof(utf8_buffer_arry[0]); ++i)
        delete[] utf8_buffer_arry[i];
}

void Sqlite3Appender::flush()
{
    RESET_LAST_ERR;
    impl_->executeNonQuerySql("COMMIT;");
}

DGR2_API const std::string& GetSqlite3LastError()
{
    return g_LastSqlite3Error;
}

NP_END
