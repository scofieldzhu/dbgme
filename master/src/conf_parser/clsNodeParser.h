#ifndef __CLS_NODE_PARSER_H__
#define __CLS_NODE_PARSER_H__

#include "confParser.h"
#include "rapidxml.hpp"

CFP_NP_BEGIN
class ClsNodeParser
{
public:      
    typedef rapidxml::xml_node<xCharT> my_xml_node;    
    virtual DGR2::DGRObject* parse(my_xml_node& cls_node) = 0;
    virtual ~ClsNodeParser() {}
};
NP_END

#endif