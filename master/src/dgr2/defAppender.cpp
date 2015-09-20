#include "defAppender.h"
#include "filter.h"

DGR2_NP_BEGIN

DefAppender::DefAppender(Filter* filter, unsigned int flush_frequence) 
    :filter_(filter),
    flush_frequence_(flush_frequence),
    finished_log_count_(0)
{
}

DefAppender::~DefAppender()
{
}

bool DefAppender::write(const Log& log)
{
    if (filter_ && !filter_->filter(log))
        return false;
    doWrite(log);        
    finished_log_count_ += 1;
    if (finished_log_count_ % flush_frequence_ == 0)
        flush();
    return true;
}

NP_END