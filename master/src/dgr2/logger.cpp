#ifdef _WIN32
#include <windows.h>
#endif
#include <algorithm>
#include "logger.h"
#include "appender.h"
#include "log.h"
using namespace std;

#define CONVERT_ARGS_TO_STR(result, fmt, ...) \
{ \
    va_list vl; \
    va_start(vl, fmt); \
    const int required_buffer_size = xvscprintf(fmt, vl); \
    xCharT* buffer = new xCharT[required_buffer_size + 1]; \
    memset(buffer, 0, sizeof(xCharT) * (required_buffer_size + 1)); \
    xVSprintf_s(buffer, required_buffer_size, fmt, vl); \
    result = buffer; \
    va_end(vl); \
    delete[] buffer; \
}

namespace {
    xStrT SplitRelativeFilePath(const xCharT* abs_filepath)
    {
        xCharT* work_dir_buffer = xGetcwd(NULL, 0);
        xStrT substr = xStrT(abs_filepath).substr(xCsLen(work_dir_buffer));
        free(work_dir_buffer);
        return substr;
    }
}

DGR2_NP_BEGIN
void Logger::publish(const Level& level, const xCharT* fmt, ...)
{
    Log log(level);
    CONVERT_ARGS_TO_STR(log.content_, fmt, __VA_ARGS__);
    this->publish(log);
}

void Logger::publish(const Level& level, const xCharT* file, const xCharT* func, unsigned int lineno, const xCharT* fmt, ...)
{
    Log log(level);
    log.logger_name_ = getName();
    CONVERT_ARGS_TO_STR(log.content_, fmt, __VA_ARGS__);
    log.func_name_ = func;
    log.filename_ = SplitRelativeFilePath(file);
    log.lineno_ = lineno;
    log.thread_id_ = ::GetCurrentThreadId();
    log.timestamp_ = LGT::DateTime::Now();
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
    AppenderListType::const_iterator iter = appenders_.begin();
    for (; iter != appenders_.end(); ++iter)
        (*iter)->write(log);
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
    name_(name)
{
}

Logger::~Logger()
{
}

NP_END
