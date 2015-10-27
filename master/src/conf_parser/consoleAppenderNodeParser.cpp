#include "consoleAppenderNodeParser.h"
#include "consoleAppender.h"
#include "confParseException.h"
#include "xtext.h"
USING_DGR2;
USING_LGT;
using namespace std;

CFP_NP_BEGIN
namespace {
    const xCharT* kFFNodeName = _X("flush_frequence");
}
DGRObject* ConsoleAppenderNodeParser::parse(my_xml_node& cls_node)
{
    DGRObject* appender = BaseAppenderNodeParser::parse(cls_node);
    if (appender == NULL)
        return NULL;
    ConsoleAppender* my_appender = dynamic_cast<ConsoleAppender*>(appender);
    my_xml_node* ffnode = cls_node.first_node(kFFNodeName);
    if (ffnode)
    {        
        int value = Str2Int(ffnode->value());
        COND_VERIFYEX(value != 0, _X("invalid %s value!\r\n"), kFFNodeName);
        my_appender->setFlushFrequence(value);
    }
    return my_appender;
}

ConsoleAppenderNodeParser::ConsoleAppenderNodeParser()
{

}

ConsoleAppenderNodeParser::~ConsoleAppenderNodeParser()
{

}

Appender* ConsoleAppenderNodeParser::createAppenderInstance()
{
    return new ConsoleAppender();
}
NP_END

