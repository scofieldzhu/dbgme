#include "locks.h"
#include <memory>
#include <Windows.h>

LGT_NP_BEGIN

struct CriticalSectionLock::Impl
{
    CRITICAL_SECTION cs_;    
};

void CriticalSectionLock::lock()
{
    ::EnterCriticalSection(&impl_->cs_);
}

void CriticalSectionLock::unlock()
{
    ::LeaveCriticalSection(&impl_->cs_);
}

CriticalSectionLock::CriticalSectionLock()
    :impl_(new Impl())
{
    InitializeCriticalSection(&impl_->cs_);
}

CriticalSectionLock::~CriticalSectionLock()
{
    ::DeleteCriticalSection(&impl_->cs_);
    delete impl_;
}
NP_END
