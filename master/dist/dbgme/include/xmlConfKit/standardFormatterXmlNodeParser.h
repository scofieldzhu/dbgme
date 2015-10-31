#ifndef __STANDARD_FORMATTER_NODE_PARSER_H__
#define __STANDARD_FORMATTER_NODE_PARSER_H__

#include "xmlClsNodeParser.h"

DGR2_NP_BEGIN
class DGR2_API StandardFormatterXmlNodeParser : public XmlClsNodeParser
{
public:
    DGR2::DGRObject* parse(my_xml_node& cls_node);
    StandardFormatterXmlNodeParser();
    ~StandardFormatterXmlNodeParser();
};
NP_END
#endif