#include "levelFilterNodeParser.h"
#include "confParseException.h"
#include "levelFilter.h"
#include "levels.h"
USING_DGR2;
using namespace std;
using namespace rapidxml;

CFP_NP_BEGIN
namespace {
    const xCharT* kLowerBoundLevelNodeName = _X("lower_bound_level");
    const xCharT* kUpperBoundLevelNodeName = _X("upper_bound_level");
}
DGRObject* LevelFilterNodeParser::parse(my_xml_node& cls_node)
{
    LevelFilter* filter = new LevelFilter();
    my_xml_node* lower_bound_node = cls_node.first_node(kLowerBoundLevelNodeName);
    if (lower_bound_node)
    {
        const xStrT node_value = lower_bound_node->value();
        Level* lower_level = LevelObjReflection::GetInstance().bornLevelObject(node_value);
        COND_VERIFYEX(lower_level != NULL, _X("%s Is Illegal Level Class!\r\n"), node_value.c_str());
        filter->setLowerBoundLevel(lower_level);
    }
    my_xml_node* upper_bound_node = cls_node.first_node(kUpperBoundLevelNodeName);
    if (upper_bound_node)
    {
        const xStrT node_value = upper_bound_node->value();
        Level* upper_level = LevelObjReflection::GetInstance().bornLevelObject(node_value);
        COND_VERIFYEX(upper_level != NULL, _X("%s Is Illegal Level Class!\r\n"), node_value.c_str());
        filter->setUpperBoundLevel(upper_level);
    }
    return filter;
}

LevelFilterNodeParser::LevelFilterNodeParser()
{

}

LevelFilterNodeParser::~LevelFilterNodeParser()
{

}

NP_END

