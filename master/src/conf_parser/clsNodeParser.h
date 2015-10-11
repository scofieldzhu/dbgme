#ifndef __CLS_NODE_PARSER_H__
#define __CLS_NODE_PARSER_H__

#include "confParser.h"
#include "rapidxml.hpp"

CFP_NP_BEGIN
template <class ClassType>
class CFP_API ClsNodeParser
{
public:
    virtual ClassType* parse(rapidxml::xml_node& cls_node) = 0;
    virtual ~ClsNodeParser() {}
};
NP_END

#endif