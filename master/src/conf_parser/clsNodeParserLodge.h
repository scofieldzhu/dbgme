#ifndef __CLS_NODE_PARSER_LODGE_H__
#define __CLS_NODE_PARSER_LODGE_H__

#include "confParser.h"
#include "uncopyable.hpp"

CFP_NP_BEGIN
class ClsNodeParserLodge : public LGT::Uncopyable
{
public:
    static ClsNodeParserLodge& GetInst();
    void join(const std::xStrT& clsname, ClsNodeParser& parser);
    ClsNodeParser* getClsNodeParser(const std::xStrT& clsname);    
private:
    ClsNodeParserLodge();
    ~ClsNodeParserLodge();
};
NP_END

#define JOIN_PARSER_LODGE(DGRCls, ParserObj) ClsNodeParserLodge::GetInst().join(_X(#DGRCls), ParserObj)

#endif