#ifndef __CONSOLE_APPENDER_NODE_PARSER_H__
#define __CONSOLE_APPENDER_NODE_PARSER_H__

#include "baseAppenderXmlNodeParser.h"

DGR2_NP_BEGIN
class DGR2_API ConsoleAppenderXmlNodeParser : public BaseAppenderXmlNodeParser
{
public:
    DGR2::DGRObject* parse(my_xml_node& cls_node);
    ConsoleAppenderXmlNodeParser();
    ~ConsoleAppenderXmlNodeParser();
private:
    DGR2::Appender* createAppenderInstance();
};
NP_END
#endif