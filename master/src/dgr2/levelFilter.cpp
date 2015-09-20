#include "levelFilter.h"
#include "log.h"
#include "level.h"
using namespace std;
DGR2_NP_BEGIN

bool LevelFilter::filter(const Log& log) const
{
    if(target_level_.get() == NULL)
        return true;
    const Level& log_level = log.getLevel();
    return log_level.getValue() >= target_level_->getValue();
}

LevelFilter::LevelFilter(const Level& level)
    :target_level_(level.clone())
{
}

LevelFilter::~LevelFilter()
{
}
NP_END


