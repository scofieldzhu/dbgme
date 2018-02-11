#include "stdafx.h"
#include <iostream>
#include "xtime.h"
#include "levelFilter.h"
#include "utilMacro.h"
#include "standardFormatter.h"
#include "consoleAppender.h"
#include "fileAppender.h"
#include "logger.h"
#include "log.h"
#include "xmlConfParser.h"
#include "xmlConfParseException.h"
#include "xmlClsNodeParserRegistrant.h"
#include "loggerMgr.h"

#include <string>

#include <windows.h>

#include "sqlite3Appender.h"

using namespace std;
USING_SFLOGGER

void TestFuncB(Logger& logger)
{
    TRACE_FUNC(logger);
    PLACE_TRACK_SLOT;
}

void TestFuncA(Logger& logger)
{
    TRACE_FUNC(logger);
    START_TRACK(logger);
    TestFuncB(logger);
}

void TestFunction(Logger& logger)
{
    TRACE_FUNC(logger);
    TestFuncA(logger);
    for (int i = 0; i < 1000000; ++i)
        ;
    STOP_TRACK;
}

int main()
{
    try
    {
        XmlClsNodeParserRegistrant regitrant;
        regitrant.registerAllParsers();
        XmlConfParser conf_parser(_X(".\\sflogger-conf.xml"));
        conf_parser.parse();
    }
    catch (XmlConfParseException& e)
    {
        xCout << _X("exception : ") << e.what_err() << endl;
        return 0;
    }

    /*WarnLevel lower;
    FatalLevel upper;
    LevelFilter filter(NULL, &upper);

    StandardFormatter formatter;

    ConsoleAppender console_appender;
    console_appender.setFormatter(&formatter);

    FileAppender file_appender(_X("test.log.txt"), 100);
    file_appender.setFormatter(&formatter);

    Logger logger(_X("Console"));
    logger.setFilter(&filter);
    logger.addAppender(console_appender);*/
    //logger.addAppender(file_appender);
    //LoggerMgr::GetInst()->addLogger(logger);


    const xCharT* x = _X("fdfdf");
    int ix = 10;
    double fx = 12.36;    
    Logger* pLogger = LoggerMgr::GetInst()->getLogger(_X("TL"));
    TestFunction(*pLogger);


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

    LoggerMgr::GetInst()->reset();
    return 0;
}