#ifndef __CONF_PARSE_EXCEPTION_H__
#define __CONF_PARSE_EXCEPTION_H__

#include "xmlConfKit.h"
#include "xtext.h"
#include <exception>

DGR2_NP_BEGIN
class DGR2_API XmlConfParseException : std::exception
{
public:
    const std::xStrT& what_err()const;
    XmlConfParseException(const xCharT* msg);
    ~XmlConfParseException();
private:
    const std::xStrT msg_;
};

#define COND_VERIFY(cond, msg) if(!(cond)) throw XmlConfParseException(msg);
#define COND_VERIFYEX(cond, fmt, ...) \
    { \
        const std::xStrT msg = ConvertArgsToString(fmt, __VA_ARGS__); \
        COND_VERIFY(cond, msg.c_str()); \
    }

NP_END

#endif