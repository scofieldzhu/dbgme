#ifndef __UNCOPYABLE_H__
#define __UNCOPYABLE_H__

#include "dgr2.h"

DGR2_NP_BEGIN
class Uncopyable
{
protected:
    Uncopyable() {}
    ~Uncopyable() {}
private:
    Uncopyable(const Uncopyable&);
    const Uncopyable& operator=(const Uncopyable&);
};
NP_END
#endif