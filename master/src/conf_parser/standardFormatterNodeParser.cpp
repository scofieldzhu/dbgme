#include "standardFormatterNodeParser.h"
#include "standardFormatter.h"
USING_DGR2;

DGR2_NP_BEGIN
DGRObject* StandardFormatterNodeParser::parse(my_xml_node& cls_node)
{
    return new StandardFormatter();
}

StandardFormatterNodeParser::StandardFormatterNodeParser()
{

}

StandardFormatterNodeParser::~StandardFormatterNodeParser()
{

}
NP_END

