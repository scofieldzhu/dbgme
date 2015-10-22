#include "confXmlParser.h"
#include "confParseException.h"
#include "xmlParserHelper.h"
#include "clsNodeParser.h"
#include "clsNodeParserLodge.h"
#include "loggerMgr.h"
#include "xtext.h"
#include "logger.h"
#include <iostream>
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

CFP_NP_BEGIN
typedef xml_document<xCharT> my_xml_document;
typedef ClsNodeParser::my_xml_node my_xml_node;
typedef ClsNodeParser::my_xml_attribute my_xml_attribute;

struct ConfXmlParser::Impl 
{
    Logger* parseLoggerNode(my_xml_node& root_node) throw (ConfParseException&);    
    void readutf8ConfContent(const xStrT& conf_file);
    void releaseResource();
    Impl();
    ~Impl();
    my_xml_document doc_;    
    xCharT* conf_filecontent_;
    int filecontent_size_;
};

Logger* ConfXmlParser::Impl::parseLoggerNode(my_xml_node& root_node) throw (ConfParseException&)
{
    my_xml_attribute* cls_attr = root_node.first_attribute(LotOfKeyAttrs::CLS_ATTR);
    COND_VERIFYEX(cls_attr != NULL, _X("%s Attribute Of Logger Xml Node Not Found!"), LotOfKeyAttrs::CLS_ATTR);
    const xStrT cls_name(cls_attr->value());
    ClsNodeParser* right_parser = ClsNodeParserLodge::GetInst().getClsNodeParser(cls_name);
    return (right_parser != NULL ? dynamic_cast<Logger*>(right_parser->parse(root_node)) : NULL);
}

void ConfXmlParser::Impl::readutf8ConfContent(const xStrT& conf_file)
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
    Utf8ToUnicode(raw_content_buffer, CONTENT_BUFFER_SIZE, conf_filecontent_, filecontent_size_);
    fclose(fp);
    delete[] raw_content_buffer;
}

ConfXmlParser::Impl::Impl()
    :conf_filecontent_(NULL),
    filecontent_size_(0)
{
}

ConfXmlParser::Impl::~Impl()
{
    releaseResource();
}

void ConfXmlParser::Impl::releaseResource()
{
    if (conf_filecontent_)
        delete[] conf_filecontent_;
    conf_filecontent_ = NULL;
    filecontent_size_ = 0;
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
    try
    {                        
        impl_->readutf8ConfContent(conf_file);
        impl_->doc_.parse<0>(impl_->conf_filecontent_);        
    }
    catch (ConfParseException& e)
    {
        impl_->releaseResource();
        throw e;
    }
    catch (parse_error& e)
    {        
        impl_->releaseResource();
        xStrT err_details = e.where<xCharT>() + AnsiToUnicode(e.what());
        throw ConfParseException(err_details.c_str());
    }    
    catch (exception& e)
    {
        impl_->releaseResource();
        xStrT err_details = AnsiToUnicode(e.what());
        throw ConfParseException(err_details.c_str());
    }
    catch (...)
    {
        impl_->releaseResource();
        throw ConfParseException(_X("Unknown Exception!"));
    }    
}

ConfXmlParser::~ConfXmlParser()
{
}
NP_END