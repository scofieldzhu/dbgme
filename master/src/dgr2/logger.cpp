#include <algorithm>
#include <cstdarg>
#include "logger.h"
#include "appender.h"
#include "filter.h"
#include "log.h"
#include "utils.h"
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

DGR2_NP_BEGIN
void Logger::publish(const Level& level, const xCharT* fmt, ...)
{
    Log log(level);
    log.logger_name_ = getName();
    CONVERT_ARGS_TO_STR(log.content_, fmt, __VA_ARGS__);
    this->publish(log);
}

void Logger::publish(const Level& level, const xCharT* file, const xCharT* func, unsigned int lineno, const xCharT* fmt, ...)
{
    Log log(level);
    log.logger_name_ = getName();    
    CONVERT_ARGS_TO_STR(log.content_, fmt, __VA_ARGS__);    
    log.func_name_ = func;
    log.filename_ = UTLS::SplitFilenameFromFullPath(file);
    log.lineno_ = lineno;    
    this->publish(log);
}

void Logger::addAppender(Appender& appender)
{
    if(find(appenders_.begin(), appenders_.end(), &appender) == appenders_.end())
        appenders_.push_back(&appender);
}

void Logger::removeAppender(Appender& appender)
{
    AppenderListType::const_iterator result = find(appenders_.begin(), appenders_.end(), &appender);
    if(result != appenders_.end())
        appenders_.erase(result);
}

void Logger::publish(Log& log)
{
    if(filter_ && !filter_->isLoggabled(log))
        return;
    AppenderListType::const_iterator iter = appenders_.begin();
    for (; iter != appenders_.end(); ++iter)
        (*iter)->publish(log);
}

Logger& Logger::operator<<(const Log& log)
{
    target_log_ = new Log(log);
    return *this;
}

Logger& Logger::operator<<(LogTag tag)
{
    switch(tag)
    {
        case endt:
            onEndLog();
            break;

        case lbt:
            xostream_ << std::endl;
            break;

        default:
            break;
    }
    return *this;
}

void Logger::onEndLog()
{    
    target_log_->content_ = xostream_.str();
    xostream_.str(_X(""));
    publish(*target_log_);
    delete target_log_;
    target_log_ = NULL;
}

Logger::Logger(const std::xStrT& name)
    :target_log_(NULL),
    name_(name),
    filter_(NULL)
{
}

Logger::~Logger()
{
    if(target_log_)
        delete target_log_;
    target_log_ = NULL;
}

NP_END
