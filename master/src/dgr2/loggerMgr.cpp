#include "loggerMgr.h"
#include <algorithm>
#include "log.h"
#include "logger.h"
#include "locks.h"
#include "autoLock.hpp"
using namespace std;

#define __GUARD__ AutoLock<CriticalSectionLock> lock;

DGR2_NP_BEGIN

LoggerMgr* LoggerMgr::inst_ = NULL;

LoggerMgr* LoggerMgr::GetInst()
{
    if(inst_ == NULL)
    {
        __GUARD__
        if(inst_ == NULL)        
            inst_ = new LoggerMgr();
    }
    return inst_;
}

void LoggerMgr::addLogger(Logger& logger)
{
    if(find(loggers_.begin(), loggers_.end(), &logger) == loggers_.end())
        loggers_.push_back(&logger);
}

struct CheckLoggerPredicate
{
    bool operator()(const Logger* logger)const
    {
        return logger->getName() == name_;
    }
    CheckLoggerPredicate(const xStrT& name)
        :name_(name)
    {}
private:
    const std::xStrT& name_;
};

Logger* LoggerMgr::getLogger(const std::xStrT& name)
{
    LoggerListType::const_iterator iter = find_if(loggers_.begin(), loggers_.end(), CheckLoggerPredicate(name));
    return (iter == loggers_.end() ? NULL : *iter);        
}

void LoggerMgr::reset()
{
    for (LoggerListType::const_iterator iter = loggers_.begin(); iter != loggers_.end(); ++iter)    
        (*iter)->destroy();
    loggers_.clear();
}

LoggerMgr::LoggerMgr()
{

}

LoggerMgr::~LoggerMgr()
{    
    reset();
}
NP_END
