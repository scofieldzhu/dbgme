#ifndef __APPENDER_H__
#define __APPENDER_H__

#include "dgrObject.h"

DGR2_NP_BEGIN
struct DGR2_API Appender : public DGRObject
{
    virtual bool publish(const Log& log) = 0;    
    virtual void setFilter(Filter* filter) = 0;
    virtual Filter* getFilter() = 0;    
    virtual void setFormatter(Formatter* formatter) = 0;
    virtual Formatter* getFormatter() = 0;    
    virtual ~Appender() {}
};
NP_END
#endif