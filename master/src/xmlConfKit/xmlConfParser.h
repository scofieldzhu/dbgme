#ifndef __CONF_XML_PARSER_H__
#define __CONF_XML_PARSER_H__

#include "xmlConfKit.h"

DGR2_NP_BEGIN
class DGR2_API XmlConfParser
{
public:    
    void parse() throw (XmlConfParseException&);
    XmlConfParser(const std::xStrT& conf_file);
    ~XmlConfParser();
private:
    struct Impl;
    std::auto_ptr<Impl> impl_;
};
NP_END

#endif