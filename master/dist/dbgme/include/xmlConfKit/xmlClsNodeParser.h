#ifndef __CLS_NODE_PARSER_H__
#define __CLS_NODE_PARSER_H__

#include "xmlConfKit.h"
#include "rapidxml.hpp"

DGR2_NP_BEGIN
class DGR2_API XmlClsNodeParser
{
public:      
    typedef rapidxml::xml_node<xCharT> my_xml_node;
    typedef rapidxml::xml_attribute<xCharT> my_xml_attribute;    
    virtual DGR2::DGRObject* parse(my_xml_node& cls_node) = 0;
    virtual ~XmlClsNodeParser() {}
};
NP_END

#endif