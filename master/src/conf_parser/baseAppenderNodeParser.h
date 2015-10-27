#ifndef __BASE_APPENDER_NODE_PARSER_H__
#define __BASE_APPENDER_NODE_PARSER_H__

#include "clsNodeParser.h"

CFP_NP_BEGIN
class CFP_API BaseAppenderNodeParser : public ClsNodeParser
{
public:
    virtual DGR2::DGRObject* parse(my_xml_node& cls_node);
    virtual ~BaseAppenderNodeParser();
protected:
    virtual DGR2::Appender* createAppenderInstance();
    virtual DGR2::Filter* parseFilter(my_xml_node& cls_node);
    virtual DGR2::Formatter* parserFormatter(my_xml_node& cls_node);
    BaseAppenderNodeParser();    
};
NP_END
#endif