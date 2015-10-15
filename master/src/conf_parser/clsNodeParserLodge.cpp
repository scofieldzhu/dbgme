#include "clsNodeParserLodge.h"

CFP_NP_BEGIN

ClsNodeParserLodge& ClsNodeParserLodge::GetInst()
{
    static ClsNodeParserLodge inst;
    return inst;
}

void ClsNodeParserLodge::join(const std::xStrT& clsname, ClsNodeParser& parser)
{

}

ClsNodeParser* ClsNodeParserLodge::getClsNodeParser(const std::xStrT& clsname)
{
    return NULL;
}

ClsNodeParserLodge::ClsNodeParserLodge()
{
}

ClsNodeParserLodge::~ClsNodeParserLodge()
{
}

NP_END
