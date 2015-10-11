#ifndef __FORMATTER_H__
#define __FORMATTER_H__

#include "dgrObject.h"

DGR2_NP_BEGIN
struct DGR2_API Formatter : public DGRObject
{
    virtual std::xStrT format(const Log& log) = 0;
    virtual ~Formatter() {}
};
NP_END
#endif