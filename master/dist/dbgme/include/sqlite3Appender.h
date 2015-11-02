#ifndef __SQLITE3_APPENDER_H__
#define __SQLITE3_APPENDER_H__

#include "defAppender.h"

DGR2_NP_BEGIN
struct DGR2_API Sqlite3Appender : public DefAppender
{
    DGR_OBJECT(Sqlite3Appender)
    Sqlite3Appender(const std::xStrT& db_file, unsigned int flush_frequence);    
private:    
    ~Sqlite3Appender();
    bool write(const Log& log, const std::xStrT& logged_msg);
    virtual void flush();
    struct Impl;
    Impl* impl_;
};
DGR2_API const std::string& GetSqlite3LastError();
NP_END

#endif
