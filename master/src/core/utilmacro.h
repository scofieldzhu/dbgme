#ifndef __utilmacro_h__
#define __utilmacro_h__

#include "xtext.h"
#include "log.h"
#include "levels.h"
#include "logger.h"
#include "tracer.h"
#include "platform.h"
#include "loggerMgr.h"

#define XLOG_DBG(plogger, fmt, ...) plogger->publish(SFLOGGER::DebugLevel(), __XFILE__, __XFUNCTION__, __LINE__, fmt, __VA_ARGS__)
#define XLOG_INF(plogger, fmt, ...) plogger->publish(SFLOGGER::InfoLevel(), __XFILE__, __XFUNCTION__, __LINE__, fmt, __VA_ARGS__)
#define XLOG_WAR(plogger, fmt, ...) plogger->publish(SFLOGGER::WarnLevel(), __XFILE__, __XFUNCTION__, __LINE__, fmt, __VA_ARGS__)
#define XLOG_ERR(plogger, fmt, ...) plogger->publish(SFLOGGER::ErrLevel(), __XFILE__, __XFUNCTION__, __LINE__, fmt, __VA_ARGS__)
#define XLOG_FAT(plogger, fmt, ...) plogger->publish(SFLOGGER::FatalLevel(), __XFILE__, __XFUNCTION__, __LINE__, fmt, __VA_ARGS__)

#define NEW_LOG(level, logger_name) \
    SFLOGGER::Log log(level); \
    log.logger_name_ = logger_name; \
    log.func_name_ = __XFUNCTION__; \
    log.filename_ = SplitFilenameFromFullPath(__XFILE__); \
    log.lineno_ = __LINE__;
#define END endt;}
#define LBT lbt

#define SXLOG_DBG(plogger) { SFLOGGER::DebugLevel l; NEW_LOG(l, plogger->getName()) (*plogger)<<log
#define SXLOG_INF(plogger) { SFLOGGER::InfoLevel l; NEW_LOG(l, plogger->getName()) (*plogger)<<log
#define SXLOG_WAR(plogger) { SFLOGGER::WarnLevel l; NEW_LOG(l, plogger->getName()) (*plogger)<<log
#define SXLOG_ERR(plogger) { SFLOGGER::ErrLevel l; NEW_LOG(l, plogger->getName()) (*plogger)<<log
#define SXLOG_FAT(plogger) { SFLOGGER::FatalLevel l; NEW_LOG(l, plogger->getName()) (*plogger)<<log

#define START_TRACK(logger) SFLOGGER::StartTrack(logger, __XFILE__, __XFUNCTION__, __LINE__);
#define STOP_TRACK SFLOGGER::StopTrack(__XFILE__, __XFUNCTION__, __LINE__);
#define PLACE_TRACK_SLOT SFLOGGER::PlaceTrackSlot(__XFILE__, __XFUNCTION__, __LINE__);
#define TRACE_FUNC(logger) SFLOGGER::FunctionTracer __ftracer__(logger, __XFILE__, __XFUNCTION__, __LINE__, true) ;

#define VERIFY(pLogger, cond) \
    if(!(cond)){ \
        XLOG_FAT(pLogger, _X("Condition:%s Failed!\r\n"), #cond); \
        SFLOGGER::DebugBreak(); \
    }

#define LOGGER(name) SFLOGGER::LoggerMgr::GetInst()->getLogger(name)

#define VERIFYEX(pLogger, cond, fmt, ...) \
    if(!(cond)) {\
        XLOG_FAT(pLogger, fmt, __VA_ARGS__);  \
        SFLOGGER::DebugBreak(); \
    }

#pragma warning(disable:4275)

#endif
