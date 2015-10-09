#include <iostream>
#include "xtime.h"
#include "loggerParser.h"
#include "levelFilter.h"
#include "logMacro.h"
#include "standardFormatter.h"
#include "consoleAppender.h"
#include "fileAppender.h"
#include "logger.h"
#include "log.h"
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
    
    FileAppender file_appender(_X("test.log.txt"), 100);
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
    XLOG_DBG(pLogger, _X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    SXLOG_DBG(pLogger) << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;
 
    XLOG_WAR(pLogger, _X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    SXLOG_WAR(pLogger) << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;
      
    XLOG_INF(pLogger, _X("\r\nHelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    SXLOG_INF(pLogger) << LBT << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;
      
    XLOG_ERR(pLogger, _X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    SXLOG_ERR(pLogger) << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;
      
    XLOG_FAT(pLogger, _X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    SXLOG_FAT(pLogger) << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << LBT << END;
	return 0;
}