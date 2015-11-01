#include <iostream>
#include "xtime.h"
#include "levelFilter.h"
#include "logMacro.h"
#include "standardFormatter.h"
#include "consoleAppender.h"
#include "fileAppender.h"
#include "logger.h"
#include "log.h"
#include "xmlConfParser.h"
#include "xmlConfParseException.h"
#include "xmlClsNodeParserRegistrant.h"
#include "loggerMgr.h"

#include "sqlite3Appender.h"
using namespace std;
USING_DGR2

int main()
{
    Sqlite3Appender db_appender(_X("test.db"), 2);
    bool result = db_appender.open();
    if (result)
    {
        cout << "db open ok!";
    }
    else
    {
        cout << "db open bad!";
    }
    StandardFormatter formatter;
    db_appender.setFormatter(&formatter);    
    Logger logger(_X("Console"));    
    logger.addAppender(db_appender);

    const xCharT* x = _X("fdfdf");
    int ix = 10;
    double fx = 12.36;

    Logger* pLogger = &logger;//LoggerMgr::GetInst()->getLogger(_X("Console"));
    XLOG_DBG(pLogger, _X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    SXLOG_DBG(pLogger) << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;

    XLOG_WAR(pLogger, _X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    SXLOG_WAR(pLogger) << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;

    XLOG_INF(pLogger, _X("\r\nHelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    SXLOG_INF(pLogger) << LBT << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;

    XLOG_ERR(pLogger, _X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    SXLOG_ERR(pLogger) << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;

    XLOG_FAT(pLogger, _X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    SXLOG_FAT(pLogger) << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;

    db_appender.close();
    return 0;


//     sqlite3* db = NULL;
//     int result = sqlite3_open_v2("test.db", &db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
//     if (result != SQLITE_OK)
//     {
//         fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//         sqlite3_close(db);
//         return 0;
//     }
// 
//     const char* query_tables = "SELECT name FROM sqlite_master WHERE type='table';";
//     const char* create_table_sql = "CREATE TABLE demo (name TEXT, age INTEGER);";
//     sqlite3_stmt* st = NULL;    
//     result = sqlite3_prepare_v2(db, query_tables, -1, &st, NULL);
//     if (result != SQLITE_OK)
//     {
//         fprintf(stderr, "sqlite3_prepare_v2 failed: %s\n", sqlite3_errmsg(db));
//         sqlite3_close(db);
//         return 0;
//     }    
//     result = sqlite3_step(st);    
//     if (result != SQLITE_DONE)
//     {
//         fprintf(stderr, "sqlite3_step failed: %s\n", sqlite3_errmsg(db));
//         sqlite3_close(db);
//         return 0;
//     }

//     while ((result = sqlite3_step(st)) == SQLITE_ROW)
//     {
//         printf("%s \n", sqlite3_column_text(st, 0));//, sqlite3_column_int(st, 1));
//     }
//     sqlite3_finalize(st);
// 
//     sqlite3_close(db);

    return 0;
    /*
    try
    {
        XmlClsNodeParserRegistrant regitrant;
        regitrant.registerAllParsers();
        XmlConfParser conf_parser(_X(".\\logger-conf.xml"));
        conf_parser.parse();
    }
    catch (XmlConfParseException& e)
    {
        xCout << _X("exception : ") << e.what_err() << endl;
    }
    */

    
    /*WarnLevel lower;
    FatalLevel upper;
    LevelFilter filter(NULL, &upper);

    StandardFormatter formatter;

    ConsoleAppender console_appender;
    console_appender.setFormatter(&formatter);

    FileAppender file_appender(_X("test.log.txt"), 100);
    file_appender.setFormatter(&formatter);

    Logger logger(_X("Console"));
    logger.setFilter(&filter);
    logger.addAppender(console_appender);*/
    //logger.addAppender(file_appender);
    //LoggerMgr::GetInst()->addLogger(logger);

    /*
    const xCharT* x = _X("fdfdf");
    int ix = 10;
    double fx = 12.36;

    Logger* pLogger = LoggerMgr::GetInst()->getLogger(_X("TL"));
    XLOG_DBG(pLogger, _X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    SXLOG_DBG(pLogger) << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;
 
    XLOG_WAR(pLogger, _X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    SXLOG_WAR(pLogger) << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;
      
    XLOG_INF(pLogger, _X("\r\nHelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    SXLOG_INF(pLogger) << LBT << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;
      
    XLOG_ERR(pLogger, _X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    SXLOG_ERR(pLogger) << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;
      
    XLOG_FAT(pLogger, _X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    SXLOG_FAT(pLogger) << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;    
	return 0;
    */
}