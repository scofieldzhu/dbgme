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

using namespace std;
USING_SFLOGGER

void TestFuncB(Logger& logger)
{
    track_this_func(logger);
    mark_track_slot();
}

void TestFuncA(Logger& logger)
{
    track_this_func(logger);
    track_now(logger);
    TestFuncB(logger);
}

void TestFunction(Logger& logger)
{
    track_this_func(logger);
    TestFuncA(logger);
    for (int i = 0; i < 1000000; ++i)
        ;
    stop_track();
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

    const xCharT* x = _X("fdfdf");
    int ix = 10;
    double fx = 12.36;    
    Logger* pLogger = LoggerMgr::GetInst()->getLogger(_X("TL"));
    TestFunction(*pLogger);

    log_debug(pLogger, _X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    log_debug(pLogger, "HelloWorld %s and %d and %f!2\r\n", x, ix, fx);
    slog_debug(pLogger).enableAutoSpace() << "HelloWorld" << x << "and" << ix << "and" << fx << std::endl;
    slog_debug(pLogger).disableAutoSpace() << _X("HelloWorld") << x << _X("and") << ix << _X("and") << fx << std::endl;

    log_warn(pLogger, _X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    slog_warn(pLogger) << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << std::endl;

    log_info(pLogger, _X("\r\nHelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    slog_info(pLogger) << std::endl << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << std::endl;

    log_err(pLogger, _X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    slog_err(pLogger) << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << std::endl;

    log_fatal(pLogger, _X("HelloWorld %s and %d and %f!\r\n"), x, ix, fx);
    slog_fatal(pLogger) << _X("HelloWorld ") << x << _X(" and ") << ix << _X(" and ") << fx << _X("!") << std::endl;

    LoggerMgr::GetInst()->reset();
    return 0;
}