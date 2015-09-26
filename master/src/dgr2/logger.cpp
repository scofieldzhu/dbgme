#include <algorithm>
#include "logger.h"
#include "filter.h"
#include "formatter.h"
#include "appender.h"
#include "log.h"
using namespace std;

DGR2_NP_BEGIN
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
    if(filter_ && !filter_->filter(log))
        return;
    if (formatter_)
        formatter_->format(log);
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
    target_log_->setContent(xostream_.str());
    xostream_.str(_X(""));
    publish(*target_log_);
    delete target_log_;
    target_log_ = NULL;
}

Logger::Logger()
    :filter_(NULL),
    formatter_(NULL),
    target_log_(NULL)
{
}

Logger::~Logger()
{
}

NP_END
