#include "confXmlParser.h"
#include "confParseException.h"
#include "xmlParserHelper.h"
#include "clsNodeParser.h"
#include "xtext.h"
using namespace std;
using namespace rapidxml;
USING_LGT;

namespace {
    namespace LotsOfKeyNodes
    {
        const xCharT* ROOT = _X("Loggers");
        const xCharT* LOGGER = _X("Logger");
    }
    namespace LotOfKeyAttrs
    {
        const xCharT* CLS_ATTR = _X("ClsAttr");
    }    
}

CFP_NP_BEGIN
typedef xml_document<xCharT> my_xml_document;
typedef ClsNodeParser::my_xml_node my_xml_node;

struct ConfXmlParser::Impl 
{
    void parseLoggerNode(my_xml_node& root_node) throw (ConfParseException&);
    my_xml_document doc_;
};

void ConfXmlParser::Impl::parseLoggerNode(my_xml_node& root_node) throw (ConfParseException&)
{

}

void ConfXmlParser::parse() throw (ConfParseException&)
{
    my_xml_node* root_node = impl_->doc_.first_node(LotsOfKeyNodes::ROOT);
    COND_VERIFYEX(root_node != NULL, _X("%s Node Not Found!"), LotsOfKeyNodes::ROOT);
    my_xml_node* logger_node = root_node->first_node(LotsOfKeyNodes::LOGGER);
    while (logger_node)
    {
        impl_->parseLoggerNode(*logger_node);
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