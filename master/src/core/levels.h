#ifndef __LEVELS_H__
#define __LEVELS_H__

#include "level.h"
#include "uncopyable.hpp"
#include <map>

SFLOGGER_NAMESPACE_BEGIN

#define NEW_LEVEL_CLASS(LevelClass, Desp, Val) \
struct LevelClass : public DefLevel{ \
    const xCharT* repr() const { return _X(#Desp); } \
    Level* clone()const { return new LevelClass(*this); } \
    LevelClass() : DefLevel(Val) {} \
    ~LevelClass(){} \
};

NEW_LEVEL_CLASS(DebugLevel, DebugLevel, 1)
NEW_LEVEL_CLASS(InfoLevel, InfoLevel, 2)
NEW_LEVEL_CLASS(WarnLevel, WarnLevel, 3)
NEW_LEVEL_CLASS(ErrLevel, ErrLevel, 4)
NEW_LEVEL_CLASS(FatalLevel, FatalLevel, 5)

struct SFLOGGER_API LevelObjReflection : public Uncopyable
{
    static LevelObjReflection& GetInstance();
    void registerLevelClass(Level& obj);
    Level* bornLevelObject(const std::xStrT& level_clsname);
private:
    LevelObjReflection();
    typedef std::map<std::xStrT, Level*> xStr2LevelDictType;
    xStr2LevelDictType level_reflection_dict_;
};

#define REGISTER_LEVEL_CLASS(LevelClass) LevelObjReflection::GetInstance().registerLevelClass(*new LevelClass())

NAMESPACE_END

#endif