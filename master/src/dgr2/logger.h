#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <vector>
#include "general.h"

DGR2_NP_BEGIN
struct DGR2_API Logger
{
    void setFilter(Filter* filter) { filter_ = filter; }
    Filter* getFilter() { return filter_; }
    const Filter* getFilter()const { return filter_; }
    void setFormatter(Formatter* formatter) { formatter_ = formatter; }
    Formatter* getFormatter() { return formatter_; }
    const Formatter* getFormatter()const { return formatter_; }
    void addAppender(Appender& appender);
    void removeAppender(Appender& appender);
    void publish(Log& log);
    Logger();
    ~Logger();
private:
    Filter* filter_;
    Formatter* formatter_;
    typedef std::vector<Appender*> AppenderListType;
    AppenderListType appenders_;
};
NP_END
#endif