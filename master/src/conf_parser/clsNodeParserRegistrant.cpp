#include "clsNodeParserRegistrant.h"
#include "clsNodeParserLodge.h"
#include "levelFilterNodeParser.h"
#include "loggerClsNodeParser.h"
#include "consoleAppenderNodeParser.h"
#include "fileAppenderNodeParser.h"
#include "standardFormatterNodeParser.h"

CFP_NP_BEGIN

void ClsNodeParserRegistrant::registerAllParsers()
{
    JOIN_PARSER_LODGE(LevelFilter, LevelFilterNodeParser)
    JOIN_PARSER_LODGE(Logger, LoggerClsNodeParser)
    JOIN_PARSER_LODGE(ConsoleAppender, ConsoleAppenderNodeParser)
    JOIN_PARSER_LODGE(FileAppender, FileAppenderNodeParser)
    JOIN_PARSER_LODGE(StandardFormatter, StandardFormatterNodeParser)
}

ClsNodeParserRegistrant::ClsNodeParserRegistrant()
{

}

ClsNodeParserRegistrant::~ClsNodeParserRegistrant()
{

}
NP_END