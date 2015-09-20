#ifndef __MY_LOG_MACROS_H__
#define __MY_LOG_MACROS_H__

#include "myLoggerDefs.h"

extern DGR::LineBreakTag lbt;
extern Logger2Mgr logger_mgr;
extern DGR::StreamEndTag endt;
extern void InitLoggers();

#define MY_LOG_DBG(fmt, ...) LOG_DBG(logger_mgr, fmt, __VA_ARGS__)
#define MY_LOG_INFO(fmt, ...) LOG_INFO(logger_mgr, fmt, __VA_ARGS__)
#define MY_LOG_WARN(fmt, ...) LOG_WARN(logger_mgr, fmt, __VA_ARGS__)
#define MY_LOG_ERR(fmt, ...) LOG_ERR(logger_mgr, fmt, __VA_ARGS__)
#define MY_LOG_FATAL(fmt, ...) LOG_FATAL(logger_mgr, fmt, __VA_ARGS__)

#define MY_LOG_DBG2 LOG_DBG2(logger_mgr)
#define MY_LOG_INFO2 LOG_INFO2(logger_mgr)
#define MY_LOG_WARN2 LOG_WARN2(logger_mgr)
#define MY_LOG_ERR2 LOG_ERR2(logger_mgr)
#define MY_LOG_FATAL2 LOG_FATAL2(logger_mgr)

#endif
