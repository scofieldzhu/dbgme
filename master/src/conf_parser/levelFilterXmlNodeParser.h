#ifndef __LEVEL_FILTER_NODE_PARSER_H__
#define __LEVEL_FILTER_NODE_PARSER_H__

#include "xmlClsNodeParser.h"

DGR2_NP_BEGIN
class LevelFilterXmlNodeParser : public XmlClsNodeParser
{
public:
    DGR2::DGRObject* parse(my_xml_node& cls_node);
    LevelFilterXmlNodeParser();
    ~LevelFilterXmlNodeParser();
};
NP_END
#endif