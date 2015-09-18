#ifndef __LEVELS_H__
#define __LEVELS_H__

#include "level.h"

DBGER2_NP_BEGIN

#define NEW_LEVEL_CLASS(LevelClass, Val) \
struct LevelClass : public DefLevel{ \
    const xCharT* Repr() const { return XT(#LevelClass); } \
    Level* Clone()const { return new LevelClass(*this); } \
    LevelClass() : DefLevel(Val) {} \
};

NEW_LEVEL_CLASS(DebugLevel, 0)
NEW_LEVEL_CLASS(InfoLevel, 1)
NEW_LEVEL_CLASS(WarnLevel, 2)
NEW_LEVEL_CLASS(ErrLevel, 3)
NEW_LEVEL_CLASS(FatalLevel, 4)

DBGER2_NP_END

#endif