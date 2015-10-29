#include "xmlClsNodeParserRegistrant.h"
#include "xmlClsNodeParserLodge.h"
#include "levelFilterXmlNodeParser.h"
#include "loggerXmlNodeParser.h"
#include "consoleAppenderXmlNodeParser.h"
#include "fileAppenderXmlNodeParser.h"
#include "standardFormatterXmlNodeParser.h"

DGR2_NP_BEGIN

void XmlClsNodeParserRegistrant::registerAllParsers()
{
    JOIN_PARSER_LODGE(LevelFilter, LevelFilterXmlNodeParser)
    JOIN_PARSER_LODGE(Logger, LoggerXmlNodeParser)
    JOIN_PARSER_LODGE(ConsoleAppender, ConsoleAppenderXmlNodeParser)
    JOIN_PARSER_LODGE(FileAppender, FileAppenderXmlNodeParser)
    JOIN_PARSER_LODGE(StandardFormatter, StandardFormatterXmlNodeParser)
}

XmlClsNodeParserRegistrant::XmlClsNodeParserRegistrant()
{

}

XmlClsNodeParserRegistrant::~XmlClsNodeParserRegistrant()
{

}
NP_END