#ifndef __MY_LOGGER_DEFS_H__
#define __MY_LOGGER_DEFS_H__

#include "dbger.h"

typedef DBGER::Logger<DBGER::SwitchFilter, DBGER::SimpleFormatter, DBGER::ConsoleAppender> SwitchSimpleLogger;
//typedef Logger<LevelFilter<ErrLevel>, SimpleFormatter, ConsoleAppender> LevelSimpleLogger;
typedef DBGER::Logger<DBGER::SwitchFilter, DBGER::SimpleFormatter, DBGER::FileAppender> SwitchSimpleFileLogger;

typedef DBGER::LoggerMgr<SwitchSimpleLogger, DBGER::utils::NullType> Logger1Mgr;
typedef DBGER::LoggerMgr<SwitchSimpleFileLogger, Logger1Mgr> Logger2Mgr;

#endif
