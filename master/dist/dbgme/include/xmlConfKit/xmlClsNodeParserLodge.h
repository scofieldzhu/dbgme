#ifndef __CLS_NODE_PARSER_LODGE_H__
#define __CLS_NODE_PARSER_LODGE_H__

#include <map>
#include "xmlConfKit.h"
#include "uncopyable.hpp"

DGR2_NP_BEGIN
class DGR2_API XmlClsNodeParserLodge : private Uncopyable
{
public:
    static XmlClsNodeParserLodge& GetInst();
    void join(const std::xStrT& clsname, XmlClsNodeParser& parser);
    XmlClsNodeParser* getClsNodeParser(const std::xStrT& clsname);    
private:
    XmlClsNodeParserLodge();
    ~XmlClsNodeParserLodge();
    typedef std::map<std::xStrT, XmlClsNodeParser*> Name2ParserMapType;
    Name2ParserMapType parser_map_;
};
NP_END

#define JOIN_PARSER_LODGE(DGRCls, ParserCls) { XmlClsNodeParser* parser = new ParserCls(); XmlClsNodeParserLodge::GetInst().join(_X(#DGRCls), *parser); }

#endif