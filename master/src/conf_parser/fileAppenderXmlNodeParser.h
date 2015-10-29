#ifndef __FILE_APPENDER_NODE_PARSER_H__
#define __FILE_APPENDER_NODE_PARSER_H__

#include "baseAppenderXmlNodeParser.h"

DGR2_NP_BEGIN
class DGR2_API FileAppenderXmlNodeParser : public BaseAppenderXmlNodeParser
{
public:
    DGR2::DGRObject* parse(my_xml_node& cls_node);
    FileAppenderXmlNodeParser();
    ~FileAppenderXmlNodeParser();
};
NP_END
#endif