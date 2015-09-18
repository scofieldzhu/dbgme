#ifndef __FORMATTER_H__
#define __FORMATTER_H__

#include "general.h"

DBGER2_NP_BEGIN

struct Formatter
{
    virtual void Format(Log& log) = 0;
    virtual ~Formatter() {}
};

DBGER2_NP_END

#endif