#include <algorithm>
#include <cstdarg>
#include "logger.h"
#include "appender.h"
#include "filter.h"
#include "log.h"
#include "xtext.h"
#include "platform.h"
#include "autoLock.hpp"
using namespace std;

#define CONVERT_ARGS_TO_STR(result, fmt, ...) \
{ \
    va_list vl; \
    va_start(vl, fmt); \
    const int required_buffer_size = xvscprintf(fmt, vl); \
    xCharT* buffer = new xCharT[required_buffer_size + 1]; \
    memset(buffer, 0, sizeof(xCharT) * (required_buffer_size + 1)); \
    xVSprintf_s(buffer, required_buffer_size + 1, fmt, vl); \
    result = buffer; \
    va_end(vl); \
    delete[] buffer; \
}

SFLOGGER_NAMESPACE_BEGIN

#define __GUARD__ AutoLock<CriticalSectionLock> lock;

void Logger::publish(const Level* level, const xCharT* fmt, ...)
{
    __GUARD__
    Log log(level);
    log.logger_name_ = getName().c_str();
    CONVERT_ARGS_TO_STR(log.content_, fmt, __VA_ARGS__);
    this->publish(log);
}

void Logger::publish(const Level* level, const xCharT* file, const xCharT* func, unsigned int lineno, const xCharT* fmt, ...)
{
    __GUARD__
    Log log(level);
    log.logger_name_ = getName().c_str();
    CONVERT_ARGS_TO_STR(log.content_, fmt, __VA_ARGS__);    
    log.func_name_ = func;
    log.filename_ = SplitFilenameFromFullPath(file);
    log.lineno_ = lineno;    
    this->publish(log);
}

void Logger::destroy()
{
    if (getFilter())
    {
        getFilter()->destroy();
        setFilter(NULL);
    }
    AppenderListType::const_iterator iter = appenders_.begin();
    for (; iter != appenders_.end(); ++iter)
        (*iter)->destroy();
    appenders_.clear();
}

void Logger::addAppender(Appender& appender)
{
    __GUARD__
    if(find(appenders_.begin(), appenders_.end(), &appender) == appenders_.end())
        appenders_.push_back(&appender);
}

void Logger::removeAppender(Appender& appender)
{
    __GUARD__
    AppenderListType::const_iterator result = find(appenders_.begin(), appenders_.end(), &appender);
    if(result != appenders_.end())
        appenders_.erase(result);
}

void Logger::publish(Log& log)
{
    __GUARD__
    if(filter_ && !filter_->isLoggabled(log))
        return;
    AppenderListType::const_iterator iter = appenders_.begin();
    for (; iter != appenders_.end(); ++iter)
        (*iter)->publish(log);
}

Logger::Logger(const std::xStrT& name)
    :name_(name),
    filter_(NULL)
{
}

Logger::~Logger()
{}

NAMESPACE_END
