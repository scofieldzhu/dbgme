#ifndef __AUTO_LOCK_HPP__
#define __AUTO_LOCK_HPP__

#include "dgr2.h"

DGR2_NP_BEGIN
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
