#include "loggerClsNodeParser.h"
#include "logger.h"
USING_DGR2;
using namespace std;
using namespace rapidxml;

CFP_NP_BEGIN

DGRObject* LoggerClsNodeParser::parse(my_xml_node& cls_node)
{
//     const int NAME_BUFFER_SIZE = cls_node.name_size() + 1;
//     xCharT* node_name = new xCharT[NAME_BUFFER_SIZE];
//     ::memset(node_name, 0, sizeof(xCharT) * NAME_BUFFER_SIZE);
    const xStrT node_name = cls_node.name();
    return NULL;
}

LoggerClsNodeParser::LoggerClsNodeParser()
{

}

LoggerClsNodeParser::~LoggerClsNodeParser()
{

}
NP_END
