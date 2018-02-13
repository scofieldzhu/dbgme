#include "log.h"
#include "level.h"
#include "platform.h"
using namespace std;

SFLOGGER_NAMESPACE_BEGIN

Log::Log(const Level* level) 
    :level_(level),
    logger_name_(NONE_STR),
    content_(_X("")),
    func_name_(NONE_STR),
    filename_(NONE_STR),
    lineno_(-1),
    thread_id_(GetPresentThreadId()),
    timestamp_(DateTime::Now())
{
}

Log::Log(const Log& rhs)
    :level_(NULL)
{    
    level_ = rhs.level_;
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
    level_ = rhs.level_;
    logger_name_ = rhs.logger_name_;
    content_ = rhs.content_;
    func_name_ = rhs.func_name_;
    filename_ = rhs.filename_;
    lineno_ = rhs.lineno_;
    thread_id_ = rhs.thread_id_;
    timestamp_ = rhs.timestamp_;
    return *this;
}
NAMESPACE_END

