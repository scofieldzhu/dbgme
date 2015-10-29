#ifndef __CONSOLE_APPENDER_NODE_PARSER_H__
#define __CONSOLE_APPENDER_NODE_PARSER_H__

#include "baseAppenderNodeParser.h"

DGR2_NP_BEGIN
class CFP_API ConsoleAppenderNodeParser : public BaseAppenderNodeParser
{
public:
    DGR2::DGRObject* parse(my_xml_node& cls_node);
    ConsoleAppenderNodeParser();
    ~ConsoleAppenderNodeParser();
private:
    DGR2::Appender* createAppenderInstance();
};
NP_END
#endif