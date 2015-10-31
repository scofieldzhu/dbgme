#ifndef __DGR_OBJECT_H__
#define __DGR_OBJECT_H__

#include "dgr2.h"

DGR2_NP_BEGIN
struct DGR2_API DGRObject
{
public:
    virtual const xCharT* getClassName()const = 0;
    virtual ~DGRObject() {}
};

#define DGR_OBJECT(ClassName) \
public: \
    const xCharT* getClassName()const { return _X(#ClassName);}

NP_END
#endif