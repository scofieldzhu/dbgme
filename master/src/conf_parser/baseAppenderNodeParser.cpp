#include "baseAppenderNodeParser.h"
#include "xmlParserHelper.h"
#include "confParseException.h"
#include "clsNodeParserLodge.h"
#include "filter.h"
#include "formatter.h"
#include "appender.h"
USING_DGR2;

CFP_NP_BEGIN
DGRObject* BaseAppenderNodeParser::parse(my_xml_node& cls_node)
{
    Appender* appender_inst = createAppenderInstance();
    COND_VERIFYEX(appender_inst != NULL, _X("createAppenderInstance failed!\r\n"));
    my_xml_node* filter_node = cls_node.first_node(LotsOfKeyNodes::FILTER);
    if (filter_node)    
        appender_inst->setFilter(parseFilter(*filter_node));    
    my_xml_node* formatter_node = cls_node.first_node(LotsOfKeyNodes::FORMATTER);
    if (formatter_node)    
        appender_inst->setFormatter(parserFormatter(*formatter_node));
    return appender_inst;
}

Appender* BaseAppenderNodeParser::createAppenderInstance()
{
    return NULL;
}

Filter* BaseAppenderNodeParser::parseFilter(my_xml_node& cls_node)
{
    my_xml_attribute* filter_cls_attr = cls_node.first_attribute(LotsOfKeyAttrs::CLS_ATTR);
    COND_VERIFYEX(filter_cls_attr != NULL, _X("%s Attr Of Filter Node Not Found!\r\n"));
    ClsNodeParser* filter_parser = ClsNodeParserLodge::GetInst().getClsNodeParser(filter_cls_attr->value());
    COND_VERIFYEX(filter_parser != NULL, _X("%s Parser Not Found!\r\n"), filter_cls_attr->value());
    Filter* filter = dynamic_cast<Filter*>(filter_parser->parse(cls_node));
    COND_VERIFYEX(filter != NULL, _X("%s Parse Failed!\r\n"), filter_cls_attr->value());
    return filter;
}

Formatter* BaseAppenderNodeParser::parserFormatter(my_xml_node& cls_node)
{
    my_xml_attribute* formatter_cls_attr = cls_node.first_attribute(LotsOfKeyAttrs::CLS_ATTR);
    COND_VERIFYEX(formatter_cls_attr != NULL, _X("%s Attr Of Formatter Node Not Found!\r\n"), LotsOfKeyAttrs::CLS_ATTR);
    ClsNodeParser* formatter_parser = ClsNodeParserLodge::GetInst().getClsNodeParser(formatter_cls_attr->value());
    COND_VERIFYEX(formatter_parser != NULL, _X("%s Parser Not Found!\r\n"), formatter_cls_attr->value());
    Formatter* formatter = dynamic_cast<Formatter*>(formatter_parser->parse(cls_node));
    COND_VERIFYEX(formatter != NULL, _X("%s Parse Failed!\r\n"), formatter_cls_attr->value());
    return formatter;
}

BaseAppenderNodeParser::BaseAppenderNodeParser()
{

}

BaseAppenderNodeParser::~BaseAppenderNodeParser()
{

}
NP_END

