#ifndef __LEVELS_H__
#define __LEVELS_H__

#include "level.h"

DGR2_NP_BEGIN

#define NEW_LEVEL_CLASS(LevelClass, Val) \
struct LevelClass : public DefLevel{ \
    const xCharT* repr() const { return _X(#LevelClass); } \
    Level* clone()const { return new LevelClass(*this); } \
    LevelClass() : DefLevel(Val) {} \
    ~LevelClass(){} \
};

NEW_LEVEL_CLASS(DebugLevel, 1)
NEW_LEVEL_CLASS(InfoLevel, 2)
NEW_LEVEL_CLASS(WarnLevel, 3)
NEW_LEVEL_CLASS(ErrLevel, 4)
NEW_LEVEL_CLASS(FatalLevel, 5)

NP_END

#endif