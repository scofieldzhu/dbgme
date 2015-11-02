#ifndef __BASE_APPENDER_NODE_PARSER_H__
#define __BASE_APPENDER_NODE_PARSER_H__

#include "xmlClsNodeParser.h"

DGR2_NP_BEGIN
class DGR2_API BaseAppenderXmlNodeParser : public XmlClsNodeParser
{
public:
    virtual DGRObject* parse(my_xml_node& cls_node);
    virtual ~BaseAppenderXmlNodeParser();
protected:
    virtual Appender* createAppenderInstance();
    virtual Filter* parseFilter(my_xml_node& cls_node);
    virtual Formatter* parserFormatter(my_xml_node& cls_node);
    virtual int parseFlushFrequnce(my_xml_node& cls_node);
    BaseAppenderXmlNodeParser();    
};
NP_END
#endif