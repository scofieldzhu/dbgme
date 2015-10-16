#include "confXmlParser.h"
#include "confParseException.h"
#include "xmlParserHelper.h"
#include "clsNodeParser.h"
#include "clsNodeParserLodge.h"
#include "loggerMgr.h"
#include "xtext.h"
#include "logger.h"
using namespace std;
using namespace rapidxml;
USING_DGR2;
USING_LGT;

namespace {
    namespace LotsOfKeyNodes
    {
        const xCharT* ROOT = _X("Loggers");
        const xCharT* LOGGER = _X("Logger");
    }
    namespace LotOfKeyAttrs
    {
        const xCharT* CLS_ATTR = _X("ClsName");
    }    
}

CFP_NP_BEGIN
typedef xml_document<xCharT> my_xml_document;
typedef xml_attribute<xCharT> my_xml_attribute;
typedef ClsNodeParser::my_xml_node my_xml_node;

struct ConfXmlParser::Impl 
{
    Logger* parseLoggerNode(my_xml_node& root_node) throw (ConfParseException&);    
    my_xml_document doc_;    
};

Logger* ConfXmlParser::Impl::parseLoggerNode(my_xml_node& root_node) throw (ConfParseException&)
{
    my_xml_attribute* cls_attr = root_node.first_attribute(LotOfKeyAttrs::CLS_ATTR);
    COND_VERIFYEX(cls_attr != NULL, _X("%s Attribute Of Logger Xml Node Not Found!"), LotOfKeyAttrs::CLS_ATTR);
    const xStrT cls_name(cls_attr->name());
    ClsNodeParser* right_parser = ClsNodeParserLodge::GetInst().getClsNodeParser(cls_name);
    return (right_parser != NULL ? dynamic_cast<Logger*>(right_parser->parse(root_node)) : NULL);
}

void ConfXmlParser::parse() throw (ConfParseException&)
{
    my_xml_node* root_node = impl_->doc_.first_node(LotsOfKeyNodes::ROOT);
    COND_VERIFYEX(root_node != NULL, _X("%s Node Not Found!"), LotsOfKeyNodes::ROOT);
    my_xml_node* logger_node = root_node->first_node(LotsOfKeyNodes::LOGGER);
    while (logger_node)
    {
        Logger* logger = impl_->parseLoggerNode(*logger_node);
        if (logger != NULL)
            LoggerMgr::GetInst()->addLogger(*logger);
        logger_node = logger_node->next_sibling(LotsOfKeyNodes::LOGGER);
    }
}

ConfXmlParser::ConfXmlParser(const std::xStrT& conf_file)
    :impl_(new Impl)
{
    try
    {
        xCharT path_buffer[300] = {_X('\0')};        
        impl_->doc_.parse<0>(path_buffer);
    }
    catch (parse_error& e)
    {
        xStrT err_details = e.where<xCharT>() + AnsiToUnicode(e.what());
        throw ConfParseException(err_details.c_str());
    }    
    catch (exception& e)
    {
        xStrT err_details = AnsiToUnicode(e.what());
        throw ConfParseException(err_details.c_str());
    }
    catch (...)
    {
        throw ConfParseException(_X("Unknown Exception!"));
    }
}

ConfXmlParser::~ConfXmlParser()
{
}
NP_END