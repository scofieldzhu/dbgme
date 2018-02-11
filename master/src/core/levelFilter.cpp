#include "levelFilter.h"
#include "log.h"
#include "level.h"
using namespace std;
SFLOGGER_NAMESPACE_BEGIN

bool LevelFilter::isLoggabled(const Log& log) const
{    
    if(log.level_)
    {
        const bool check_left_bound_result = (lower_bound_level_ ? log.level_->getValue() >= lower_bound_level_->getValue() : true);
        const bool check_right_bound_result = (upper_bound_level_ ? log.level_->getValue() < upper_bound_level_->getValue() : true);
        return check_left_bound_result && check_right_bound_result;
    }
    return false;    
}

void LevelFilter::setUpperBoundLevel(const Level* level)
{
    if (upper_bound_level_)
    {
        delete upper_bound_level_;
        upper_bound_level_ = NULL;
    }    
    if(level != NULL)
        upper_bound_level_ = level->clone();
}

const Level* LevelFilter::getUpperBoundLevel() const
{
    return upper_bound_level_;
}

void LevelFilter::setLowerBoundLevel(const Level* level)
{
    if(lower_bound_level_)
    {
        delete lower_bound_level_;
        lower_bound_level_ = NULL;
    }
    if(level != NULL)
        lower_bound_level_ = level->clone();
}

const Level* LevelFilter::getLowerBoundLevel() const
{
    return lower_bound_level_;
}

LevelFilter::LevelFilter(const Level* lower, const Level* upper)
    :lower_bound_level_(NULL),
    upper_bound_level_(NULL)
{
    setLowerBoundLevel(lower);
    setUpperBoundLevel(upper);    
}

LevelFilter::~LevelFilter()
{
    if(lower_bound_level_)
        delete lower_bound_level_;
    if(upper_bound_level_)
        delete upper_bound_level_;
}
NAMESPACE_END


