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
#define LOG_WAR(fmt, ...) _PUBLISH_LOG(DGR2::WarnLevel(), fmt, __VA_ARGS__)
#define LOG_ERR(fmt, ...) _PUBLISH_LOG(DGR2::ErrLevel(), fmt, __VA_ARGS__)
#define LOG_FAT(fmt, ...) _PUBLISH_LOG(DGR2::FatalLevel(), fmt, __VA_ARGS__)

#define _SLOG(level) { __NEW_LOG(level, _X("")); (*DGR2::LoggerMgr::GetInst())<<(log)
#define END endt;}
#define LBT lbt

#define SLOG_DBG _SLOG(DGR2::DebugLevel())
#define SLOG_INF _SLOG(DGR2::InfoLevel())
#define SLOG_WAR _SLOG(DGR2::WarnLevel())
#define SLOG_ERR _SLOG(DGR2::ErrLevel())
#define SLOG_FAT _SLOG(DGR2::FatalLevel())


#define XLOG_DBG(logger, fmt, ...) logger->publish(DGR2::DebugLevel(), __XFILE__, __XFUNCTION__, __LINE__, fmt, __VA_ARGS__)
#define XLOG_INF(logger, fmt, ...) logger->publish(DGR2::InfoLevel(), __XFILE__, __XFUNCTION__, __LINE__, fmt, __VA_ARGS__)
#define XLOG_WAR(logger, fmt, ...) logger->publish(DGR2::WarnLevel(), __XFILE__, __XFUNCTION__, __LINE__, fmt, __VA_ARGS__)
#define XLOG_ERR(logger, fmt, ...) logger->publish(DGR2::ErrLevel(), __XFILE__, __XFUNCTION__, __LINE__, fmt, __VA_ARGS__)
#define XLOG_FAT(logger, fmt, ...) logger->publish(DGR2::FatalLevel(), __XFILE__, __XFUNCTION__, __LINE__, fmt, __VA_ARGS__)


#endif
