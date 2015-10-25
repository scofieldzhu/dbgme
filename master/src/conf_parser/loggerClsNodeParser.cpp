#include "loggerClsNodeParser.h"
#include "confParseException.h"
#include "xmlParserHelper.h"
#include "clsNodeParserLodge.h"
#include "logger.h"
#include "appender.h"
#include "filter.h"
USING_DGR2;
using namespace std;
using namespace rapidxml;

namespace {    
    namespace KeyChildOfLoggerNode{
        const xCharT* Name = _X("Name");
        const xCharT* Appenders = _X("Appenders");
    }
    typedef std::vector<Appender*> AppenderList;
}

CFP_NP_BEGIN

DGRObject* LoggerClsNodeParser::parse(my_xml_node& cls_node)
{
    const xStrT kNodeName = cls_node.name();    
    COND_VERIFYEX(kNodeName == LotsOfKeyNodes::LOGGER, _X("RootNode is not %s.\r\n"), LotsOfKeyNodes::LOGGER);

    my_xml_node* name_node = cls_node.first_node(KeyChildOfLoggerNode::Name);
    COND_VERIFYEX(name_node != NULL, _X("<%s> ChildNode Not Found!\r\n"), KeyChildOfLoggerNode::Name);
    const xStrT name_value = name_node->value();

    Filter* logger_filter = NULL;
    my_xml_node* filter_node = cls_node.first_node(LotsOfKeyNodes::FILTER);
    if (filter_node)
    {
        my_xml_attribute* filter_clsname = filter_node->first_attribute(LotsOfKeyAttrs::CLS_ATTR);
        COND_VERIFYEX(filter_clsname != NULL, _X("%s Attribute Of Filter Node Not Found!\r\n"), LotsOfKeyAttrs::CLS_ATTR);
        ClsNodeParser* filter_parser = ClsNodeParserLodge::GetInst().getClsNodeParser(filter_clsname->value());
        COND_VERIFYEX(filter_parser != NULL, _X("%s Parser Not Found!\r\n"), filter_clsname->value());
        DGRObject* filter_dgrobj = filter_parser->parse(*filter_node);
        logger_filter = dynamic_cast<Filter*>(filter_dgrobj);
        COND_VERIFYEX(logger_filter != NULL, _X("%s Parse Failed!\r\n"), filter_clsname->value());
    }
    
    my_xml_node* appenders_node = cls_node.first_node(KeyChildOfLoggerNode::Appenders);
    COND_VERIFYEX(name_node != NULL, _X("<%s> ChildNode Not Found!\r\n"), KeyChildOfLoggerNode::Appenders);
    my_xml_node* appender_node = appenders_node->first_node(LotsOfKeyNodes::APPENDER);
    AppenderList appender_list;    
    while (appender_node != NULL)
    {
        my_xml_attribute* attri = appender_node->first_attribute(LotsOfKeyAttrs::CLS_ATTR);
        COND_VERIFYEX(attri != NULL, _X("%s Attribute Of <%s> Node Not Found!\r\n"), LotsOfKeyAttrs::CLS_ATTR, LotsOfKeyNodes::APPENDER);
        ClsNodeParser* appender_parser = ClsNodeParserLodge::GetInst().getClsNodeParser(attri->name());
        COND_VERIFYEX(appender_parser != NULL, _X("Could Not Found %s XmlParser!\r\n"), attri->name());
        DGRObject* appender_dgrobj = appender_parser->parse(*appender_node);
        Appender* appender = dynamic_cast<Appender*>(appender_dgrobj);
        COND_VERIFYEX(appender != NULL, _X("Parse %s Node Failed!\r\n"), attri->name());
        appender_list.push_back(appender);
        appender_node = appender_node->next_sibling(LotsOfKeyNodes::APPENDER);
    };
    
    Logger* new_logger = new Logger(name_value);
    for (AppenderList::const_iterator iter = appender_list.begin(); iter != appender_list.end(); ++iter)
        new_logger->addAppender(*(*iter));
    return new_logger;
}

LoggerClsNodeParser::LoggerClsNodeParser()
{

}

LoggerClsNodeParser::~LoggerClsNodeParser()
{

}
NP_END
