#ifndef __LANGEXT_H__
#define __LANGEXT_H__

#include "basicType.h"

#include "autoLock.h"
#include "locks.h"
#define __GUARD__ LGT::AutoLock<LGT::CriticalSectionLock> lock;

#endif