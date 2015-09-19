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
	LogType log = DGR::details::AssembleLog<LogType>(content, file, func, lineno);
    mgr.publish(log);
}

#define LOG_DBG(mgr, fmt, vars) PublishLog<DGR::DebugLog>(mgr, DGR::details::ConvertArgsToString(fmt, vars), _XFILE_, _XFUNCTION_, __LINE__)
#define LOG_INFO(mgr, fmt, ...) PublishLog<DGR::InfoLog>(mgr, DGR::details::ConvertArgsToString(fmt, __VA_ARGS__), _XFILE_, _XFUNCTION_, __LINE__)
#define LOG_WARN(mgr, fmt, ...) PublishLog<DGR::WarnLog>(mgr, DGR::details::ConvertArgsToString(fmt, __VA_ARGS__), _XFILE_, _XFUNCTION_, __LINE__)
#define LOG_ERR(mgr, fmt, ...) PublishLog<DGR::ErrLog>(mgr, DGR::details::ConvertArgsToString(fmt, __VA_ARGS__), _XFILE_, _XFUNCTION_, __LINE__)
#define LOG_FATAL(mgr, fmt, ...) PublishLog<DGR::FatalLog>(mgr, DGR::details::ConvertArgsToString(fmt, __VA_ARGS__), _XFILE_, _XFUNCTION_, __LINE__)

template 
<	
	class LogType,
    class LoggerMgrT
>
LoggerMgrT& PublishLog2(LoggerMgrT& mgr, const xCharT* file, const xCharT* func, int lineno)
{
	LogType log = DGR::details::AssembleLog<LogType>(XT(""), file, func, lineno);
	mgr << log;
	return mgr;
}

#define LOG_DBG2(mgr) PublishLog2<DGR::DebugLog>(mgr, _XFILE_, _XFUNCTION_, __LINE__)
#define LOG_INFO2(mgr) PublishLog2<DGR::InfoLog>(mgr, _XFILE_, _XFUNCTION_, __LINE__)
#define LOG_WARN2(mgr) PublishLog2<DGR::WarnLog>(mgr, _XFILE_, _XFUNCTION_, __LINE__)
#define LOG_ERR2(mgr) PublishLog2<DGR::ErrLog>(mgr, _XFILE_, _XFUNCTION_, __LINE__)
#define LOG_FATAL2(mgr) PublishLog2<DGR::FatalLog>(mgr, _XFILE_, _XFUNCTION_, __LINE__)

#endif