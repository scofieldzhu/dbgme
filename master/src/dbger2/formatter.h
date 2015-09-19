#ifndef __FORMATTER_H__
#define __FORMATTER_H__

#include "general.h"
#include "dr2DllExport.h"

DGR2_NP_BEGIN
struct DGR2_API Formatter
{
    virtual void format(Log& log) = 0;
    virtual ~Formatter() {}
};
NP_END
#endif