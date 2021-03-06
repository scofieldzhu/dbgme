#include "defAppender.h"
#include "filter.h"
#include "formatter.h"
#include "log.h"
using namespace std;

SFLOGGER_NAMESPACE_BEGIN

DefAppender::DefAppender(unsigned int flush_frequence) 
    :filter_(NULL),
    formatter_(NULL),
    flush_frequence_(flush_frequence),
    finished_log_count_(0)
{
}

DefAppender::~DefAppender()
{
}

bool DefAppender::publish(const Log& log)
{
    if(filter_ && !filter_->isLoggabled(log))
        return false;
    xStrT logged_msg = log.content_;
    if (formatter_)
        logged_msg = formatter_->format(log);
    if (!write(log, logged_msg))
        return false;
    finished_log_count_ += 1;
    if(finished_log_count_ % flush_frequence_ == 0)
        flush();
    return true;
}

NAMESPACE_END