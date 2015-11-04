#ifndef __TRACER_H__
#define __TRACER_H__

#include "dgr2.h"

DGR2_NP_BEGIN

DGR2_API void StartTrack(Logger& logger, xCharT* file, const xCharT* function, int lineno);
DGR2_API void StopTrack(const xCharT* file, const xCharT* function, int lineno);
DGR2_API void PlaceTrackSlot(const xCharT* file, const xCharT* function, int lineno);

struct DGR2_API FunctionTracer
{
    FunctionTracer(Logger& logger, const xCharT* file,  const xCharT* function, int lineno, bool trace_time_wasted);
    ~FunctionTracer();
private:
    struct Impl;
    Impl* impl_;
};

NP_END
#endif