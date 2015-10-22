#include "loggerClsNodeParser.h"
#include "confParseException.h"
#include "xmlParserHelper.h"
#include "logger.h"
USING_DGR2;
using namespace std;
using namespace rapidxml;

namespace {    
    namespace KeyChildOfLoggerNode{
        const xCharT* Name = _X("Name");
        const xCharT* Appenders = _X("Appenders");
    }
}

CFP_NP_BEGIN

DGRObject* LoggerClsNodeParser::parse(my_xml_node& cls_node)
{
    const xStrT kNodeName = cls_node.name();    
    COND_VERIFYEX(kNodeName == LotsOfKeyNodes::LOGGER, _X("RootNode is not %s.\r\n"), LotsOfKeyNodes::LOGGER);
    my_xml_node* name_node = cls_node.first_node(KeyChildOfLoggerNode::Name);
    COND_VERIFYEX(name_node != NULL, _X("<%s> ChildNode Not Found!\r\n"), KeyChildOfLoggerNode::Name);
    my_xml_node* appenders = cls_node.first_node(KeyChildOfLoggerNode::Appenders);
    COND_VERIFYEX(name_node != NULL, _X("<%s> ChildNode Not Found!\r\n"), KeyChildOfLoggerNode::Appenders);
    Logger* new_logger = new Logger(name_node->value());
    



    return NULL;
}

LoggerClsNodeParser::LoggerClsNodeParser()
{

}

LoggerClsNodeParser::~LoggerClsNodeParser()
{

}
NP_END
