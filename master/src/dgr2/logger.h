#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <vector>
#include <sstream>
#include "general.h"
#include "logTag.h"

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
    template <typename T>
    Logger& operator<<(T val)
    {
        xostream_ << val;
        return *this;
    }
    Logger& operator<<(const Log& log);
    Logger& operator<<(LogTag tag);
    Logger();
    ~Logger();

private:
    void onEndLog();
    Filter* filter_;
    Formatter* formatter_;
    typedef std::vector<Appender*> AppenderListType;
    AppenderListType appenders_;
    std::basic_ostringstream<xCharT> xostream_;
    Log* target_log_;
};
NP_END
#endif