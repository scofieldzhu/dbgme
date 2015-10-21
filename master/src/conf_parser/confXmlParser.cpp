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

#define SAFE_RELEASE_FILE_BUFFER \
    if(file_content_buffer != NULL) \
    { \
        delete[] file_content_buffer; \
        file_content_buffer = NULL; \
    }        

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
    void transformUnicodeStringFromUtf8ConfContent(const xStrT& conf_file, xCharT*& buffer, int* buffer_size);
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

void ConfXmlParser::Impl::transformUnicodeStringFromUtf8ConfContent(const xStrT& conf_file, xCharT*& conf_file_content, int* content_len)
{    
    FILE* fp = NULL;
    errno_t error = xfopen(&fp, conf_file.c_str(), _X("rb,ccs=UTF-8"));
    COND_VERIFYEX(error == 0, _X("%s not exists!\r\n"), conf_file.c_str());
    fseek(fp, 0, SEEK_END);     
    const int CONTENT_BUFFER_SIZE = ftell(fp) - 3; 
    rewind(fp);        
    char* raw_content_buffer = new char[CONTENT_BUFFER_SIZE];    
    fread(raw_content_buffer, 1, 3, fp);//jump over file BOM:\xef\xbb\xbf
    const int numberOfItemsFinished = fread(raw_content_buffer, 1, CONTENT_BUFFER_SIZE, fp);
    COND_VERIFY(numberOfItemsFinished == CONTENT_BUFFER_SIZE, _X("read conf file failed!"));        
    int return_len = 0;
    Utf8ToUnicode(raw_content_buffer, CONTENT_BUFFER_SIZE, conf_file_content, return_len);
    if (content_len != NULL)
        *content_len = return_len;
    fclose(fp);
}

void ConfXmlParser::parse() throw (ConfParseException&)
{
    my_xml_node* root_node = impl_->doc_.first_node(LotsOfKeyNodes::ROOT);
    COND_VERIFYEX(root_node != NULL, _X("%s Node Not Found!"), LotsOfKeyNodes::ROOT);
    my_xml_node* logger_node = root_node->first_node(LotsOfKeyNodes::LOGGER);
    while (logger_node)
    {
        Logger* logger = impl_->parseLoggerNode(*logger_node);
        COND_VERIFYEX(logger != NULL, _X("LoggerXmlNode Parsed Error!\r\n"));
        LoggerMgr::GetInst()->addLogger(*logger);
        logger_node = logger_node->next_sibling(LotsOfKeyNodes::LOGGER);
    }
}

ConfXmlParser::ConfXmlParser(const std::xStrT& conf_file)
    :impl_(new Impl)
{
    xCharT* file_content_buffer = NULL;
    try
    {                        
        impl_->transformUnicodeStringFromUtf8ConfContent(conf_file, file_content_buffer, NULL);
        impl_->doc_.parse<0>(file_content_buffer);
        SAFE_RELEASE_FILE_BUFFER;
    }
    catch (ConfParseException& e)
    {
        SAFE_RELEASE_FILE_BUFFER;
        throw e;
    }
    catch (parse_error& e)
    {        
        SAFE_RELEASE_FILE_BUFFER;
        xStrT err_details = e.where<xCharT>() + AnsiToUnicode(e.what());
        throw ConfParseException(err_details.c_str());
    }    
    catch (exception& e)
    {
        SAFE_RELEASE_FILE_BUFFER;
        xStrT err_details = AnsiToUnicode(e.what());
        throw ConfParseException(err_details.c_str());
    }
    catch (...)
    {
        SAFE_RELEASE_FILE_BUFFER;
        throw ConfParseException(_X("Unknown Exception!"));
    }    
}

ConfXmlParser::~ConfXmlParser()
{
}
NP_END