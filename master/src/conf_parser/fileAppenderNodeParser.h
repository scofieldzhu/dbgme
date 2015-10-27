#ifndef __FILE_APPENDER_NODE_PARSER_H__
#define __FILE_APPENDER_NODE_PARSER_H__

#include "baseAppenderNodeParser.h"

CFP_NP_BEGIN
class CFP_API FileAppenderNodeParser : public BaseAppenderNodeParser
{
public:
    DGR2::DGRObject* parse(my_xml_node& cls_node);
    FileAppenderNodeParser();
    ~FileAppenderNodeParser();
};
NP_END
#endif