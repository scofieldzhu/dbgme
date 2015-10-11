#ifndef __LOG_H__
#define __LOG_H__

#include "dgr2.h"
#include "xtime.h"

DGR2_NP_BEGIN

struct DGR2_API Log
{    
    Log& operator=(const Log& rhs);
    Log(const Log& rhs);
    Log(const Level& level);
    ~Log();

    const Level* level_;
    std::xStrT logger_name_;    
    std::xStrT content_;
    std::xStrT func_name_;
    std::xStrT filename_;
    unsigned int lineno_;
    unsigned int thread_id_;
    LGT::DateTime timestamp_;    
};

NP_END
#endif