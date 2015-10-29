#ifndef __LOGGER_CLS_NODE_PARSER_H__
#define __LOGGER_CLS_NODE_PARSER_H__

#include "xmlClsNodeParser.h"

DGR2_NP_BEGIN
class DGR2_API LoggerXmlNodeParser : public XmlClsNodeParser
{
public:
    DGR2::DGRObject* parse(my_xml_node& cls_node);
    LoggerXmlNodeParser();
    virtual ~LoggerXmlNodeParser();
};
NP_END
#endif