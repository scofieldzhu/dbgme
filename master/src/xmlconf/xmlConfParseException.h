#ifndef __CONF_PARSE_EXCEPTION_H__
#define __CONF_PARSE_EXCEPTION_H__

#include "xmlconfpublic.h"
#include "xtext.h"
#include <exception>

SFLOGGER_NAMESPACE_BEGIN
class XmlConfParseException : std::exception
{
public:
    const std::xStrT& what_err()const { return msg_; }
    XmlConfParseException(const xCharT* msg)
        :std::exception(nullptr),
        msg_(msg){}
    ~XmlConfParseException() = default;
private:
    const std::xStrT msg_;
};

#define COND_VERIFY(cond, msg) if(!(cond)) throw XmlConfParseException(msg);
#define COND_VERIFYEX(cond, fmt, ...) \
    { \
        const std::xStrT msg = ConvertArgsToString(fmt, __VA_ARGS__); \
        COND_VERIFY(cond, msg.c_str()); \
    }

NAMESPACE_END

#endif