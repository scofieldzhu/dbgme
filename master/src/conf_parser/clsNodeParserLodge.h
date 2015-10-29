#ifndef __CLS_NODE_PARSER_LODGE_H__
#define __CLS_NODE_PARSER_LODGE_H__

#include <map>
#include "confParser.h"
#include "uncopyable.hpp"

DGR2_NP_BEGIN
class CFP_API ClsNodeParserLodge : public LGT::Uncopyable
{
public:
    static ClsNodeParserLodge& GetInst();
    void join(const std::xStrT& clsname, ClsNodeParser& parser);
    ClsNodeParser* getClsNodeParser(const std::xStrT& clsname);    
private:
    ClsNodeParserLodge();
    ~ClsNodeParserLodge();
    typedef std::map<std::xStrT, ClsNodeParser*> Name2ParserMapType;
    Name2ParserMapType parser_map_;
};
NP_END

#define JOIN_PARSER_LODGE(DGRCls, ParserCls) { ClsNodeParser* parser = new ParserCls(); ClsNodeParserLodge::GetInst().join(_X(#DGRCls), *parser); }

#endif