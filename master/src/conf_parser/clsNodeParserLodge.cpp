#include "clsNodeParserLodge.h"

CFP_NP_BEGIN

ClsNodeParserLodge& ClsNodeParserLodge::GetInst()
{
    static ClsNodeParserLodge inst;
    return inst;
}

void ClsNodeParserLodge::join(const std::xStrT& clsname, ClsNodeParser& parser)
{
    Name2ParserMapType::const_iterator iter = parser_map_.find(clsname);
    if (iter == parser_map_.end())
        parser_map_[clsname] = &parser;
}

ClsNodeParser* ClsNodeParserLodge::getClsNodeParser(const std::xStrT& clsname)
{
    Name2ParserMapType::const_iterator iter = parser_map_.find(clsname);    
    return (iter == parser_map_.end() ? NULL : (*iter).second);
}

ClsNodeParserLodge::ClsNodeParserLodge()
{
}

ClsNodeParserLodge::~ClsNodeParserLodge()
{
}

NP_END
