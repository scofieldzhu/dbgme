#ifndef __SQLITE3_APPENDER_XMLNODE_PARSER_H__
#define __SQLITE3_APPENDER_XMLNODE_PARSER_H__

#include "baseAppenderXmlNodeParser.h"

DGR2_NP_BEGIN
class DGR2_API Sqlite3AppenderXmlNodeParser : public BaseAppenderXmlNodeParser
{
public:
    DGRObject* parse(my_xml_node& cls_node);
    Sqlite3AppenderXmlNodeParser();
    ~Sqlite3AppenderXmlNodeParser();
};
NP_END
#endif