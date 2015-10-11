#include "confXmlParser.h"
#include "confParseException.h"
#include "xmlParserHelper.h"
#include "xtext.h"
using namespace std;
using namespace rapidxml;
USING_LGT;

CFP_NP_BEGIN

struct ConfXmlParser::Impl 
{
    xml_document<xCharT> doc_;
};

bool ConfXmlParser::parse()
{
    return false;
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