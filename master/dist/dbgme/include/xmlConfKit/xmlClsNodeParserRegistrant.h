#ifndef __CLS_NODE_PARSER_REGISTRANT_H__
#define __CLS_NODE_PARSER_REGISTRANT_H__

#include "xmlConfKit.h"

DGR2_NP_BEGIN
class DGR2_API XmlClsNodeParserRegistrant 
{
public:
    virtual void registerAllParsers();
    XmlClsNodeParserRegistrant();
    virtual ~XmlClsNodeParserRegistrant();
};
NP_END

#endif