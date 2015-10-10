#ifndef __CONF_XML_PARSER_H__
#define __CONF_XML_PARSER_H__

#include "confParser.h"

CFP_NP_BEGIN
template <class ClassType>
class CFP_API ConfXmlParser
{
public:
    virtual ClassType* parse(rapidxml::xml_node& cls_node) = 0;
    virtual ~ConfXmlParser() {}
};
NP_END

#endif