#ifndef __APPENDER_H__
#define __APPENDER_H__

#include "general.h"

DGR2_NP_BEGIN
struct DGR2_API Appender
{
    virtual bool write(const Log& log) = 0;
    virtual void flush() = 0;
    virtual void setFilter(Filter* filter) = 0;
    virtual Filter* getFilter() = 0;
    virtual const Filter* getFilter()const = 0;
    virtual ~Appender() {}
};
NP_END
#endif