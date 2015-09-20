#ifndef __LEVEL_FILTER_H__
#define __LEVEL_FILTER_H__

#include "filter.h"

DGR2_NP_BEGIN
struct DGR2_API LevelFilter : public Filter
{
    bool filter(const Log& log)const;
    LevelFilter(const Level& level);
    ~LevelFilter();
private:    
    std::auto_ptr<Level> target_level_;
};
NP_END
#endif
