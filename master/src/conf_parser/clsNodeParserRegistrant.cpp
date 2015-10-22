#include "clsNodeParserRegistrant.h"
#include "clsNodeParserLodge.h"
#include "levelFilterNodeParser.h"
#include "loggerClsNodeParser.h"

CFP_NP_BEGIN

void ClsNodeParserRegistrant::registerAllParsers()
{
    JOIN_PARSER_LODGE(LevelFilter, LevelFilterNodeParser)
    JOIN_PARSER_LODGE(Logger, LoggerClsNodeParser)
}

ClsNodeParserRegistrant::ClsNodeParserRegistrant()
{

}

ClsNodeParserRegistrant::~ClsNodeParserRegistrant()
{

}
NP_END