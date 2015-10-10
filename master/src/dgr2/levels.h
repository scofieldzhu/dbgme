#ifndef __LEVELS_H__
#define __LEVELS_H__

#include "level.h"

DGR2_NP_BEGIN

#define NEW_LEVEL_CLASS(LevelClass, Desp, Val) \
struct LevelClass : public DefLevel{ \
    const xCharT* repr() const { return _X(#Desp); } \
    Level* clone()const { return new LevelClass(*this); } \
    LevelClass() : DefLevel(Val) {} \
    ~LevelClass(){} \
};

NEW_LEVEL_CLASS(DebugLevel, Dbg, 1)
NEW_LEVEL_CLASS(InfoLevel, Info, 2)
NEW_LEVEL_CLASS(WarnLevel, Warn, 3)
NEW_LEVEL_CLASS(ErrLevel, Err, 4)
NEW_LEVEL_CLASS(FatalLevel, Fat, 5)

NP_END

#endif