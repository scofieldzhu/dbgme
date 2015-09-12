#include "myLoggerDefs.h"

USING_DBGER

LineBreakTag lbt;
StreamEndTag endt;
SwitchSimpleLogger console_logger;
SwitchSimpleFileLogger file_logger;
Logger2Mgr logger_mgr;

void InitLoggers()
{
	logger_mgr.SetL(console_logger);
	logger_mgr.SetL(file_logger);
}