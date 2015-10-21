#ifndef __LOGGER_MGR_H__
#define __LOGGER_MGR_H__

#include <vector>
#include "dgr2.h"
#include "logTag.h"
#include "logger.h"
#include "uncopyable.hpp"

DGR2_NP_BEGIN
class DGR2_API LoggerMgr : private LGT::Uncopyable
{
public:
    static LoggerMgr* GetInst();
    void addLogger(Logger& logger);
    Logger* getLogger(const std::xStrT& name);

private:
    LoggerMgr();    
    ~LoggerMgr();
    typedef std::vector<Logger*> LoggerListType;
    LoggerListType loggers_;
    static LoggerMgr* inst_;
};
NP_END
#endif
