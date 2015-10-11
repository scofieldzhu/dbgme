#ifndef __CONF_XML_PARSER_H__
#define __CONF_XML_PARSER_H__

#include "confParser.h"

CFP_NP_BEGIN
class CFP_API ConfXmlParser
{
public:
    void parse() throw (ConfParseException&);
    ConfXmlParser(const std::xStrT& conf_file);
    ~ConfXmlParser();
private:
    struct Impl;
    std::auto_ptr<Impl> impl_;
};
NP_END

#endif