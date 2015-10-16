#include "clsNodeParserRegistrant.h"
#include "clsNodeParserLodge.h"
#include "levelFilterNodeParser.h"

CFP_NP_BEGIN

void ClsNodeParserRegistrant::registerAllParsers()
{
    JOIN_PARSER_LODGE(LevelFilter, LevelFilterNodeParser)
}

ClsNodeParserRegistrant::ClsNodeParserRegistrant()
{

}

ClsNodeParserRegistrant::~ClsNodeParserRegistrant()
{

}
NP_END