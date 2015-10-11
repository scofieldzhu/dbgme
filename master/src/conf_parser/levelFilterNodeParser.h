#ifndef __LEVEL_FILTER_NODE_PARSER_H__
#define __LEVEL_FILTER_NODE_PARSER_H__

#include "clsNodeParser.h"
#include "levelFilter.h"

CFP_NP_BEGIN
class LevelFilterNodeParser : public ClsNodeParser
{
public:
    DGR2::LevelFilter* parse(my_xml_node& cls_node);
    LevelFilterNodeParser();
    ~LevelFilterNodeParser();
};
NP_END
#endif