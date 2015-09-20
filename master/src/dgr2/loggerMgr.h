#ifndef __LOGGER_MGR_H__
#define __LOGGER_MGR_H__

#include <vector>
#include "general.h"

DGR2_NP_BEGIN
class DGR2_API LoggerMgr
{
public:
    static LoggerMgr* GetInst();
    void addLogger(Logger& logger);
    void publish(const Log& log);
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
