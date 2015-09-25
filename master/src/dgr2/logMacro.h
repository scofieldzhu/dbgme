#ifndef __LOG_MACRO_H__
#define __LOG_MACRO_H__

#include "utils.h"
#include "log.h"
#include "levels.h"
#include "loggerMgr.h"

#define __NEW_LOG(level, content) DGR2::Log log(level, content, __XFUNCTION__, DGR2::UTLS::SplitRelativeFilePath(__XFILE__), __LINE__)
#define _NEW_LOG(level, fmt, ...) __NEW_LOG(level, DGR2::UTLS::ConvertArgsToString(fmt, __VA_ARGS__))
#define _PUBLISH_LOG(level, fmt, ...) { _NEW_LOG(level, fmt, __VA_ARGS__); DGR2::LoggerMgr::GetInst()->publish(log); }

#define LOG_DBG(fmt, ...) _PUBLISH_LOG(DGR2::DebugLevel(), fmt, __VA_ARGS__)
#define LOG_INF(fmt, ...) _PUBLISH_LOG(DGR2::InfoLevel(), fmt, __VA_ARGS__)
#define LOG_WARN(fmt, ...) _PUBLISH_LOG(DGR2::WarnLevel(), fmt, __VA_ARGS__)
#define LOG_ERR(fmt, ...) _PUBLISH_LOG(DGR2::ErrLevel(), fmt, __VA_ARGS__)
#define LOG_FAT(fmt, ...) _PUBLISH_LOG(DGR2::FatalLevel(), fmt, __VA_ARGS__)

#define _SLOG(level) { __NEW_LOG(level, _X("")); (*DGR2::LoggerMgr::GetInst())<<(log)
#define _SLOG_DBG _SLOG(DGR2::DebugLevel())
#define END endt;}

#define SLOG_DBG _SLOG_DBG

#endif
