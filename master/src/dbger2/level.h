#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "general.h"

DGR2_NP_BEGIN

struct Level
{
    virtual int GetValue() const = 0;
    virtual const xCharT* Repr() const = 0;
    virtual Level* Clone()const = 0;
    virtual ~Level() {}
};

struct DefLevel : public Level
{
    int GetValue() const { return val_; }
    DefLevel(int val)
        :val_(val)
    {}
private:
    int val_;
};

NP_END
#endif