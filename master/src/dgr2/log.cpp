#include "log.h"
#include "level.h"
USING_LGT

DGR2_NP_BEGIN

Log::Log(const Level& level, const std::xStrT& content, const std::xStrT& func_name, const std::xStrT& filename, unsigned int lineno) 
    :level_(level.clone()),
    content_(content),
    func_name_(func_name),
    filename_(filename),
    lineno_(lineno),
    timestamp_(DateTime::Now())
{
}

Log::Log(const Log& rhs)
{
    level_ = rhs.level_->clone();
    content_ = rhs.content_;
    func_name_ = rhs.func_name_;
    filename_ = rhs.filename_;
    lineno_ = rhs.lineno_;
    timestamp_ = rhs.timestamp_;
}

const Log& Log::operator=(const Log& rhs)
{
    if (level_)
        delete level_;
    level_ = rhs.level_->clone();
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

NP_END

