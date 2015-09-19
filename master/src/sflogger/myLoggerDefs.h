#ifndef __MY_LOGGER_DEFS_H__
#define __MY_LOGGER_DEFS_H__

#include "dbger.h"

typedef DGR::Logger<DGR::SwitchFilter, DGR::SimpleFormatter, DGR::ConsoleAppender> SwitchSimpleLogger;
//typedef Logger<LevelFilter<ErrLevel>, SimpleFormatter, ConsoleAppender> LevelSimpleLogger;
typedef DGR::Logger<DGR::SwitchFilter, DGR::SimpleFormatter, DGR::FileAppender> SwitchSimpleFileLogger;

typedef DGR::LoggerMgr<SwitchSimpleLogger, DGR::NullType> Logger1Mgr;
typedef DGR::LoggerMgr<SwitchSimpleFileLogger, Logger1Mgr> Logger2Mgr;

#endif
