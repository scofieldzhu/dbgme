#ifndef __LOGGER_MGR_H__
#define __LOGGER_MGR_H__

#include <vector>
#include "general.h"
#include "logTag.h"
#include "logger.h"

DGR2_NP_BEGIN
class DGR2_API LoggerMgr
{
public:
    static LoggerMgr* GetInst();
    void addLogger(Logger& logger);
    void publish(const Log& log);
    template <typename T>
    LoggerMgr& operator<<(T val)
    {
        LoggerListType::const_iterator iter = loggers_.begin();
        for (; iter != loggers_.end(); ++iter)
        {
            (*iter)->operator<<(val);
        }
        return *this;
    }
    LoggerMgr& operator<<(const Log& log);
private:
    LoggerMgr();
    LoggerMgr(const LoggerMgr&);
    ~LoggerMgr();
    typedef std::vector<Logger*> LoggerListType;
    LoggerListType loggers_;
    static LoggerMgr* inst_;
};
NP_END
#endif
