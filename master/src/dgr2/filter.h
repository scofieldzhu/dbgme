#ifndef __FILTER_H__
#define __FILTER_H__

#include "general.h"
#include "dr2DllExport.h"

DGR2_NP_BEGIN
struct DGR2_API Filter
{
    virtual bool isLoggabled(const Log& log)const = 0;
    virtual ~Filter() {}
};
NP_END
#endif
