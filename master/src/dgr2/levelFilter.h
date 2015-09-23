#ifndef __LEVEL_FILTER_H__
#define __LEVEL_FILTER_H__

#include "filter.h"

DGR2_NP_BEGIN
struct DGR2_API LevelFilter : public Filter
{
    bool filter(const Log& log)const;
    void setLowerBoundLevel(const Level* level);
    const Level* getLowerBoundLevel()const;
    void setUpperBoundLevel(const Level* level);
    const Level* getUpperBoundLevel()const;     
    LevelFilter(const Level* lower = NULL, const Level* upper = NULL);
    ~LevelFilter();
private:        
    Level* lower_bound_level_;
    Level* upper_bound_level_;
};
NP_END
#endif
