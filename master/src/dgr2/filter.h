#ifndef __FILTER_H__
#define __FILTER_H__

#include "dgrObject.h"

DGR2_NP_BEGIN
struct DGR2_API Filter : public DGRObject
{
    virtual bool isLoggabled(const Log& log)const = 0;
protected:
    virtual ~Filter() {}
};
NP_END
#endif
