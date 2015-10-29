#include "standardFormatterXmlNodeParser.h"
#include "standardFormatter.h"
USING_DGR2;

DGR2_NP_BEGIN
DGRObject* StandardFormatterXmlNodeParser::parse(my_xml_node& cls_node)
{
    return new StandardFormatter();
}

StandardFormatterXmlNodeParser::StandardFormatterXmlNodeParser()
{

}

StandardFormatterXmlNodeParser::~StandardFormatterXmlNodeParser()
{

}
NP_END

