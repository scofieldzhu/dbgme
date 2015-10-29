#include "fileAppenderXmlNodeParser.h"
#include "fileAppender.h"
#include "xmlConfParseException.h"
#include "xmlParserHelper.h"
#include "xtext.h"
USING_DGR2;
using namespace std;

DGR2_NP_BEGIN
namespace {
    const xCharT* kFilePathNodeName = _X("file_path");
    const xCharT* kFFNodeName = _X("flush_frequence");
}

DGRObject* FileAppenderXmlNodeParser::parse(my_xml_node& cls_node)
{    
    my_xml_node* filepath_node = cls_node.first_node(kFilePathNodeName);
    COND_VERIFYEX(filepath_node != NULL, _X("%s Child Node Of Appender Node Not Found!\r\n"), kFilePathNodeName);
    const xStrT filepath = filepath_node->value();    
    
    my_xml_node* ffnode = cls_node.first_node(kFFNodeName);
    COND_VERIFYEX(ffnode != NULL, _X("%s Child Node Of Appender Node Not Found!\r\n"), kFFNodeName);
    const int value = Str2Int(ffnode->value());
    COND_VERIFYEX(value != 0, _X("invalid %s value!\r\n"), kFFNodeName);

    FileAppender* file_appender = new FileAppender(filepath, value);

    my_xml_node* filter_node = cls_node.first_node(LotsOfKeyNodes::FILTER);
    if (filter_node)
        file_appender->setFilter(parseFilter(*filter_node));

    my_xml_node* formatter_node = cls_node.first_node(LotsOfKeyNodes::FORMATTER);
    if (formatter_node)
        file_appender->setFormatter(parserFormatter(*formatter_node));

    return file_appender;
}

FileAppenderXmlNodeParser::FileAppenderXmlNodeParser()
{

}

FileAppenderXmlNodeParser::~FileAppenderXmlNodeParser()
{

}

NP_END
