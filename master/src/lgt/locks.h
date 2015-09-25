#ifndef __LOCKS_H__
#define __LOCKS_H__

#include "basicType.h"
#include "lgtDLLExport.h"

LGT_NP_BEGIN
class LGT_API CriticalSectionLock
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
