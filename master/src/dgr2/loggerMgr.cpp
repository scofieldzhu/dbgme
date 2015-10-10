#include <algorithm>
#include "loggerMgr.h"
#include "log.h"
#include "logger.h"
using namespace std;

DGR2_NP_BEGIN
USING_LGT

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

LoggerMgr::LoggerMgr()
{

}

LoggerMgr::~LoggerMgr()
{
    loggers_.clear();
}
NP_END
