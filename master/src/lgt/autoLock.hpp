#ifndef __AUTO_LOCK_HPP__
#define __AUTO_LOCK_HPP__

#include "basicType.h"

LGT_NP_BEGIN
template <class L>
class AutoLock
{
public:
    AutoLock() { obj_.lock(); }
    ~AutoLock() { obj_.unlock(); }
private:
    L obj_;
};
NP_END

#endif
