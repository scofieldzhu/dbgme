#ifndef __DGR2_MACRO_H__
#define __DGR2_MACRO_H__

#include "xtext.h"
#include "log.h"
#include "levels.h"
#include "logger.h"
#include "tracer.h"
#include "platform.h"

#define XLOG_DBG(plogger, fmt, ...) plogger->publish(DGR2::DebugLevel(), __XFILE__, __XFUNCTION__, __LINE__, fmt, __VA_ARGS__)
#define XLOG_INF(plogger, fmt, ...) plogger->publish(DGR2::InfoLevel(), __XFILE__, __XFUNCTION__, __LINE__, fmt, __VA_ARGS__)
#define XLOG_WAR(plogger, fmt, ...) plogger->publish(DGR2::WarnLevel(), __XFILE__, __XFUNCTION__, __LINE__, fmt, __VA_ARGS__)
#define XLOG_ERR(plogger, fmt, ...) plogger->publish(DGR2::ErrLevel(), __XFILE__, __XFUNCTION__, __LINE__, fmt, __VA_ARGS__)
#define XLOG_FAT(plogger, fmt, ...) plogger->publish(DGR2::FatalLevel(), __XFILE__, __XFUNCTION__, __LINE__, fmt, __VA_ARGS__)

#define NEW_LOG(level, logger_name) \
    DGR2::Log log(level); \
    log.logger_name_ = logger_name; \
    log.func_name_ = __XFUNCTION__; \
    log.filename_ = SplitFilenameFromFullPath(__XFILE__); \
    log.lineno_ = __LINE__;
#define END endt;}
#define LBT lbt

#define SXLOG_DBG(plogger) { DGR2::DebugLevel l; NEW_LOG(l, plogger->getName()) (*plogger)<<log
#define SXLOG_INF(plogger) { DGR2::InfoLevel l; NEW_LOG(l, plogger->getName()) (*plogger)<<log
#define SXLOG_WAR(plogger) { DGR2::WarnLevel l; NEW_LOG(l, plogger->getName()) (*plogger)<<log
#define SXLOG_ERR(plogger) { DGR2::ErrLevel l; NEW_LOG(l, plogger->getName()) (*plogger)<<log
#define SXLOG_FAT(plogger) { DGR2::FatalLevel l; NEW_LOG(l, plogger->getName()) (*plogger)<<log

#define START_TRACK(logger) DGR2::StartTrack(logger, __XFILE__, __XFUNCTION__, __LINE__);
#define STOP_TRACK DGR2::StopTrack(__XFILE__, __XFUNCTION__, __LINE__);
#define PLACE_TRACK_SLOT DGR2::PlaceTrackSlot(__XFILE__, __XFUNCTION__, __LINE__);
#define TRACE_FUNC(logger) DGR2::FunctionTracer __ftracer__(logger, __XFILE__, __XFUNCTION__, __LINE__, true) ;

#define VERIFY(pLogger, cond) \
    if(!(cond)){ \
        XLOG_FAT(pLogger, _X("Condition:%s Failed!\r\n"), #cond); \
        DGR2::DebugBreak(); \
    }

#define VERIFYEX(pLogger, cond, fmt, ...) \
    if(!(cond)) {\
        XLOG_FAT(pLogger, fmt, __VA_ARGS__);  \
        DGR2::DebugBreak(); \
    }

#endif
