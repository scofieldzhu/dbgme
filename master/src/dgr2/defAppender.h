#ifndef __DEFAPPENDER_H__
#define __DEFAPPENDER_H__

#include "appender.h"

DGR2_NP_BEGIN
struct DGR2_API DefAppender : public Appender
{    
    void setFilter(Filter* filter) { filter_ = filter; }
    Filter* getFilter() { return filter_; }
    const Filter* getFilter()const { return filter_; }

    void setFlushFrequence(unsigned int frequence) { flush_frequence_ = frequence; }
    unsigned int getFlushFrequnce()const { return flush_frequence_; }

    int getFinishedLogCount()const { return finished_log_count_; }
        
    virtual ~DefAppender();

protected:
    DefAppender(Filter* filter, unsigned int flush_frequence);
    virtual void doWrite(const Log& log) = 0;

private:
    bool write(const Log& log);
    Filter* filter_;
    unsigned int flush_frequence_;
    unsigned int finished_log_count_;
};
NP_END
#endif
