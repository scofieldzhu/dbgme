#ifndef __CONF_PARSE_EXCEPTION_H__
#define __CONF_PARSE_EXCEPTION_H__

#include "confParser.h"
#include "xtext.h"
#include <exception>

CFP_NP_BEGIN
class CFP_API ConfParseException : std::exception
{
public:
    const std::xStrT& what_err()const;
    ConfParseException(const xCharT* msg);
    ~ConfParseException();
private:
    const std::xStrT msg_;
};

#define COND_VERIFY(cond, msg) if(!(cond)) throw ConfParseException(msg);
#define COND_VERIFYEX(cond, fmt, ...) \
    { \
        const std::xStrT msg = LGT::ConvertArgsToString(fmt, __VA_ARGS__); \
        COND_VERIFY(cond, msg.c_str()); \
    }

NP_END

#endif