#ifndef __SQLITE3_APPENDER_H__
#define __SQLITE3_APPENDER_H__

#include "defAppender.h"

DGR2_NP_BEGIN
class DGR2_API Sqlite3Appender : public DefAppender
{
public:
    bool open();
    void close();
    Sqlite3Appender(const std::xStrT& db_file, unsigned int flush_frequence);
    ~Sqlite3Appender();
private:
    void write(const Log& log, const std::xStrT& logged_msg);
    virtual void flush();
    struct Impl;
    Impl* impl_;
};
DGR2_API const std::string& GetSqlite3LastError();
NP_END

#endif
