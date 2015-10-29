#ifndef __CLS_NODE_PARSER_REGISTRANT_H__
#define __CLS_NODE_PARSER_REGISTRANT_H__

#include "confParser.h"

DGR2_NP_BEGIN
class CFP_API ClsNodeParserRegistrant 
{
public:
    virtual void registerAllParsers();
    ClsNodeParserRegistrant();
    virtual ~ClsNodeParserRegistrant();
};
NP_END

#endif