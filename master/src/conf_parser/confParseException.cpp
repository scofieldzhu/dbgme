#include "confParseException.h"

CFP_NP_BEGIN
const std::xStrT& ConfParseException::what_err() const
{
    return msg_;
}

ConfParseException::ConfParseException(const xCharT* msg)
    :std::exception(NULL),
    msg_(msg)
{
}

ConfParseException::~ConfParseException()
{
}
NP_END