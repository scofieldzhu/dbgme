#ifndef __CONF_PARSE_EXCEPTION_H__
#define __CONF_PARSE_EXCEPTION_H__

#include "confParser.h"
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
NP_END

#endif