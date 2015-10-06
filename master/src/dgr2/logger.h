#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <vector>
#include <sstream>
#include "general.h"
#include "logTag.h"

DGR2_NP_BEGIN
struct DGR2_API Logger
{    
    const std::xStrT& getName()const { return name_; }
    void addAppender(Appender& appender);
    void removeAppender(Appender& appender);
    void publish(Log& log);
    void publish(const Level& level, const xCharT* fmt, ...);
    void publish(const Level& level, const xCharT* file, const xCharT* func, unsigned int lineno, const xCharT* fmt, ...);
    template <typename T>
    Logger& operator<<(T val)
    {
        xostream_ << val;
        return *this;
    }
    Logger& operator<<(const Log& log);
    Logger& operator<<(LogTag tag);
    Logger(const std::xStrT& name);
    ~Logger();

private:
    void onEndLog();    
    typedef std::vector<Appender*> AppenderListType;
    AppenderListType appenders_;
    std::basic_ostringstream<xCharT> xostream_;
    Log* target_log_;
    std::xStrT name_;
};
NP_END
#endif