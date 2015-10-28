#include "levels.h"

DGR2_NP_BEGIN

namespace {
    struct LevelAutoReigster
    {
        LevelAutoReigster()
        {
            REGISTER_LEVEL_CLASS(DebugLevel);
            REGISTER_LEVEL_CLASS(InfoLevel);
            REGISTER_LEVEL_CLASS(WarnLevel);
            REGISTER_LEVEL_CLASS(ErrLevel);
            REGISTER_LEVEL_CLASS(FatalLevel);
        }
    }__auto_register__;
}

LevelObjReflection::LevelObjReflection()
{
}

Level* LevelObjReflection::bornLevelObject(const std::xStrT& level_clsname)
{
    xStr2LevelDictType::const_iterator iter = level_reflection_dict_.find(level_clsname);
    if (iter == level_reflection_dict_.end())
        return NULL;
    return level_reflection_dict_[level_clsname]->clone();
}

void LevelObjReflection::registerLevelClass(Level& obj)
{
    const std::xStrT obj_clsname = obj.repr();
    xStr2LevelDictType::const_iterator iter = level_reflection_dict_.find(obj_clsname);
    if (iter == level_reflection_dict_.end())
        level_reflection_dict_[obj_clsname] = &obj;
}

LevelObjReflection& LevelObjReflection::GetInstance()
{
    static LevelObjReflection reflection;
    return reflection;
}
NP_END