#ifndef __DGR_OBJECT_H__
#define __DGR_OBJECT_H__

#include "dgr2.h"

DGR2_NP_BEGIN
struct DGR2_API DGRObject
{
    virtual void destroy() { delete this; } //only created object by new method
    virtual const xCharT* getClassName()const = 0;
protected:
    virtual ~DGRObject() {}
};

#define DGR_OBJECT(ClassName) \
public: \
    const xCharT* getClassName()const { return _X(#ClassName);}

NP_END
#endif