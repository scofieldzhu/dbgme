#ifndef __LOG_MACRO_H__
#define __LOG_MACRO_H__

#include "utils.h"
#include "log.h"
#include "levels.h"
#include "loggerMgr.h"

#define __NewLog(level, fmt, args) \
    DGR2::Log log(level, \
                             DGR2::UTLS::ConvertArgsToString(fmt, args), \
                             __XFUNCTION__, \
                             DGR2::UTLS::SplitRelativeFilePath(__XFILE__), \
                             __LINE__)

#define __PUBLISH_LOG(level, fmt, ...) { \
        std::xStrT content = DGR2::UTLS::ConvertArgsToString(fmt, __VA_ARGS__); \
        std::xStrT filename = DGR2::UTLS::SplitRelativeFilePath(__XFILE__); \
        DGR2::Log log(level, content, __XFUNCTION__, filename, __LINE__); \
        DGR2::LoggerMgr::GetInst()->publish(log); \
     }
#define LOG_DBG(fmt, ...) __PUBLISH_LOG(DGR2::DebugLevel(), fmt, __VA_ARGS__)
#define LOG_INF(fmt, ...) __PUBLISH_LOG(DGR2::InfoLevel(), fmt, __VA_ARGS__)
#define LOG_WARN(fmt, ...) __PUBLISH_LOG(DGR2::WarnLevel(), fmt, __VA_ARGS__)
#define LOG_ERR(fmt, ...) __PUBLISH_LOG(DGR2::ErrLevel(), fmt, __VA_ARGS__)
#define LOG_FAT(fmt, ...) __PUBLISH_LOG(DGR2::FatalLevel(), fmt, __VA_ARGS__)

#endif
