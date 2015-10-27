#ifndef __STANDARD_FORMATTER_NODE_PARSER_H__
#define __STANDARD_FORMATTER_NODE_PARSER_H__

#include "clsNodeParser.h"

CFP_NP_BEGIN
class CFP_API StandardFormatterNodeParser : public ClsNodeParser
{
public:
    DGR2::DGRObject* parse(my_xml_node& cls_node);
    StandardFormatterNodeParser();
    ~StandardFormatterNodeParser();
};
NP_END
#endif