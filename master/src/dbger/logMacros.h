#ifndef __LOG_MACROS_H__
#define __LOG_MACROS_H__

#include "logAssistor.hpp"

template 
<
    class LogType,
    class LoggerMgrT
>
void PublishLog(LoggerMgrT& mgr, std::xStrT content, const xCharT* file, const xCharT* func, int lineno)
{
	LogType log = DBGER::details::AssembleLog<LogType>(content, file, func, lineno);
    mgr.Publish(log);
}

#define LOG_DBG(mgr, fmt, vars) PublishLog<DBGER::DebugLog>(mgr, DBGER::details::ConvertArgsToString(fmt, vars), _XFILE_, _XFUNCTION_, __LINE__)
#define LOG_INFO(mgr, fmt, ...) PublishLog<DBGER::InfoLog>(mgr, DBGER::details::ConvertArgsToString(fmt, __VA_ARGS__), _XFILE_, _XFUNCTION_, __LINE__)
#define LOG_WARN(mgr, fmt, ...) PublishLog<DBGER::WarnLog>(mgr, DBGER::details::ConvertArgsToString(fmt, __VA_ARGS__), _XFILE_, _XFUNCTION_, __LINE__)
#define LOG_ERR(mgr, fmt, ...) PublishLog<DBGER::ErrLog>(mgr, DBGER::details::ConvertArgsToString(fmt, __VA_ARGS__), _XFILE_, _XFUNCTION_, __LINE__)
#define LOG_FATAL(mgr, fmt, ...) PublishLog<DBGER::FatalLog>(mgr, DBGER::details::ConvertArgsToString(fmt, __VA_ARGS__), _XFILE_, _XFUNCTION_, __LINE__)

template 
<	
	class LogType,
    class LoggerMgrT
>
LoggerMgrT& PublishLog2(LoggerMgrT& mgr, const xCharT* file, const xCharT* func, int lineno)
{
	LogType log = DBGER::details::AssembleLog<LogType>(XT(""), file, func, lineno);
	mgr << log;
	return mgr;
}

#define LOG_DBG2(mgr) PublishLog2<DBGER::DebugLog>(mgr, _XFILE_, _XFUNCTION_, __LINE__)
#define LOG_INFO2(mgr) PublishLog2<DBGER::InfoLog>(mgr, _XFILE_, _XFUNCTION_, __LINE__)
#define LOG_WARN2(mgr) PublishLog2<DBGER::WarnLog>(mgr, _XFILE_, _XFUNCTION_, __LINE__)
#define LOG_ERR2(mgr) PublishLog2<DBGER::ErrLog>(mgr, _XFILE_, _XFUNCTION_, __LINE__)
#define LOG_FATAL2(mgr) PublishLog2<DBGER::FatalLog>(mgr, _XFILE_, _XFUNCTION_, __LINE__)

#endif