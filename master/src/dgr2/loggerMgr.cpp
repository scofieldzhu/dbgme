#include <algorithm>
#include "loggerMgr.h"
#include "log.h"
#include "logger.h"
using namespace std;
DGR2_NP_BEGIN

LoggerMgr* LoggerMgr::inst_ = NULL;

LoggerMgr* LoggerMgr::GetInst()
{
    if(inst_ == NULL)
        inst_ = new LoggerMgr();
    return inst_;
}

void LoggerMgr::addLogger(Logger& logger)
{
    if(find(loggers_.begin(), loggers_.end(), &logger) == loggers_.end())
        loggers_.push_back(&logger);
}

void LoggerMgr::publish(const Log& log)
{
    LoggerListType::const_iterator iter = loggers_.begin();
    for (; iter != loggers_.end(); ++iter)
    {
        Log clone(log);
        (*iter)->publish(clone);
    }
}

LoggerMgr::LoggerMgr()
{

}

LoggerMgr::~LoggerMgr()
{

}
NP_END
