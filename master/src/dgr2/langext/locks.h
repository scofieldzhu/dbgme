#ifndef __LOCKS_H__
#define __LOCKS_H__

#include "dgr2.h"

DGR2_NP_BEGIN

class DGR2_API CriticalSectionLock
{
public:
    void lock();
    void unlock();    
    CriticalSectionLock();
    ~CriticalSectionLock();
private:
    struct Impl;
    Impl* impl_;
};

NP_END
#endif
