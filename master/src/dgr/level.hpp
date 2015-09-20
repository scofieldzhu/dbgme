#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "general.hpp"

DGR_NP_BEGIN

#define NEW_LEVEL_TYPE(ClassType, Value) \
struct ClassType {\
	static const xCharT* GetDesp() { return XT(#ClassType); } \
	static int GetLevelVal() { return Value; } \
};

NEW_LEVEL_TYPE(DebugLevel, 0)
NEW_LEVEL_TYPE(InfoLevel, 1)
NEW_LEVEL_TYPE(WarnLevel, 2)
NEW_LEVEL_TYPE(ErrLevel, 3)
NEW_LEVEL_TYPE(FatalLevel, 4)

NP_END

#endif