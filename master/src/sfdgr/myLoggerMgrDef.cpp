#include "myLoggerDefs.h"
USING_DGR

LineBreakTag lbt;
StreamEndTag endt;
SwitchSimpleLogger console_logger(XT("ConsoleLogger"));
SwitchSimpleFileLogger file_logger(XT("FileLogger"));
Logger2Mgr logger_mgr;

void InitLoggers()
{
	logger_mgr.setL(console_logger);
	logger_mgr.setL(file_logger);
}