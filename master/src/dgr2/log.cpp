#include "log.h"
#include "level.h"
#ifdef IN_WINOS
#include <Windows.h>
#endif
using namespace std;
USING_LGT

DGR2_NP_BEGIN

Log::Log(const Level& level) 
    :level_(&level),
    logger_name_(NONE_STR),
    content_(_X("")),
    func_name_(NONE_STR),
    filename_(NONE_STR),
    lineno_(-1),
#ifdef IN_WINOS
    thread_id_(GetCurrentThreadId()),
#else
    thread_id_(-1),
#endif
    timestamp_(DateTime::Now())
{
}

Log::Log(const Log& rhs)
{
    if (level_ != NULL)
        delete level_;
    level_ = NULL;
    if(rhs.level_)
        level_ = rhs.level_->clone();
    logger_name_ = rhs.logger_name_;
    content_ = rhs.content_;
    func_name_ = rhs.func_name_;
    filename_ = rhs.filename_;
    lineno_ = rhs.lineno_;
    thread_id_ = rhs.thread_id_;
    timestamp_ = rhs.timestamp_;
}

Log& Log::operator=(const Log& rhs)
{
    if (level_ != NULL)
        delete level_;
    level_ = NULL;
    if (rhs.level_)
        level_ = rhs.level_->clone();
    logger_name_ = rhs.logger_name_;
    content_ = rhs.content_;
    func_name_ = rhs.func_name_;
    filename_ = rhs.filename_;
    lineno_ = rhs.lineno_;
    thread_id_ = rhs.thread_id_;
    timestamp_ = rhs.timestamp_;
    return *this;
}

Log::~Log()
{
    if (level_)
        delete level_;
    level_ = NULL;
}

NP_END

