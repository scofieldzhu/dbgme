#include "log.h"
#include "level.h"
USING_DBGER2
USING_UTILS

Log::Log(const Level& level, const std::xStrT& content, const std::xStrT& func_name, const std::xStrT& filename, int lineno) 
    :level_(level.Clone()),
    content_(content),
    func_name_(func_name),
    filename_(filename),
    lineno_(lineno),
    timestamp_(DateTime::Now())
{
}

const Log& Log::operator=(const Log& rhs)
{
    if (level_)
        delete level_;
    level_ = rhs.level_->Clone();
    content_ = rhs.content_;
    func_name_ = rhs.func_name_;
    filename_ = rhs.filename_;
    lineno_ = rhs.lineno_;
    timestamp_ = rhs.timestamp_;
    return *this;
}

Log::~Log()
{
    if (level_)
        delete level_;
}

