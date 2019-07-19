#include "xmlClsNodeParserLodge.h"
#include "levelFilterXmlNodeParser.h"
#include "loggerXmlNodeParser.h"
#include "consoleAppenderXmlNodeParser.h"
#include "fileAppenderXmlNodeParser.h"
#include "standardFormatterXmlNodeParser.h"
#include "sqlite3AppenderXmlNodeParser.h"

SFLOGGER_NAMESPACE_BEGIN

XmlClsNodeParserLodge& XmlClsNodeParserLodge::GetInst()
{
    static XmlClsNodeParserLodge inst;
    return inst;
}

XmlClsNodeParserLodge::XmlClsNodeParserLodge()
{
    joinSysParsers();
}

XmlClsNodeParserLodge::~XmlClsNodeParserLodge()
{}

void XmlClsNodeParserLodge::join(const std::xStrT& clsname, XmlClsNodeParser& parser)
{
    Name2ParserMapType::const_iterator iter = parser_map_.find(clsname);
    if (iter == parser_map_.end())
        parser_map_[clsname] = &parser;
}

XmlClsNodeParser* XmlClsNodeParserLodge::getClsNodeParser(const std::xStrT& clsname)
{
    Name2ParserMapType::const_iterator iter = parser_map_.find(clsname);    
    return (iter == parser_map_.end() ? NULL : (*iter).second);
}

void XmlClsNodeParserLodge::joinSysParsers()
{
    join("LevelFilter", *new LevelFilterXmlNodeParser());
    join("Logger", *new LoggerXmlNodeParser());
    join("ConsoleAppender", *new ConsoleAppenderXmlNodeParser());
    join("FileAppender", *new FileAppenderXmlNodeParser());
    join("StandardFormatter", *new StandardFormatterXmlNodeParser());
    join("Sqlite3Appender", *new Sqlite3AppenderXmlNodeParser());    
}
NAMESPACE_END
