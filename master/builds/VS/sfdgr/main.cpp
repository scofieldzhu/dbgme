#include <iostream>
#include "xtime.h"
#include "loggerParser.h"
#include "levelFilter.h"
#include "logMacro.h"
#include "standardFormatter.h"
#include "consoleAppender.h"
#include "fileAppender.h"
#include "logger.h"
#include <iomanip>
using namespace std;
USING_DGR2
USING_LGT

int main()
{
    WarnLevel lower;
    FatalLevel upper;
    LevelFilter filter(NULL, &upper);

    StandardFormatter formatter;
    
    ConsoleAppender console_appender;
    console_appender.setFormatter(&formatter);
    
    FileAppender file_appender(_X("test.log.txt"), 2);
    file_appender.setFormatter(&formatter);
    
    Logger logger(_X("TestLogger"));
    logger.setFilter(&filter);    
    logger.addAppender(console_appender);
    //logger.addAppender(file_appender);
    //LoggerMgr::GetInst()->addLogger(logger);

    const xCharT* x = _X("fdfdf");
    int ix = 10;
    double fx = 12.36;

    Logger* pLogger = &logger;
    XLOG_DBG(pLogger, _X("\r\nHelloWorld %s and %d and %f!\r\n"), x, ix, fx);

//     LOG_DBG(_X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
//     SLOG_DBG << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;
//     
//     LOG_INF(_X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
//     SLOG_INF << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;
//     
//     LOG_WAR(_X("\r\nHelloWorld %s and %d and %f!\r\n"), x, ix, fx);
//     SLOG_WAR << LBT << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;
//     
//     LOG_ERR(_X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
//     SLOG_ERR << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;
//     
//     LOG_FAT(_X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
//     SLOG_FAT << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;
	return 0;
}