#include "logstream.h"
#include "logger.h"
#include "log.h"
#include "xtext.h"

SFLOGGER_NAMESPACE_BEGIN
LogStream& LogStream::operator<<(bool val)
{
    oss_ << val;
    if (autospace_)
        oss_ << _X(' ');
    return *this;
}

LogStream& LogStream::operator<<(short val)
{
    oss_ << val;
    if (autospace_)
        oss_ << _X(' ');
    return *this;
}

LogStream& LogStream::operator<<(unsigned short val)
{
    oss_ << val;
    if (autospace_)
        oss_ << _X(' ');
    return *this;
}

LogStream& LogStream::operator<<(int val)
{
    oss_ << val;
    if (autospace_)
        oss_ << _X(' ');
    return *this;
}

LogStream& LogStream::operator<<(unsigned int val)
{
    oss_ << val;
    if (autospace_)
        oss_ << _X(' ');
    return *this;
}

LogStream& LogStream::operator<<(long val)
{
    oss_ << val;
    if (autospace_)
        oss_ << _X(' ');
    return *this;
}

LogStream& LogStream::operator<<(unsigned long val)
{
    oss_ << val;
    if (autospace_)
        oss_ << _X(' ');
    return *this;
}

LogStream& LogStream::operator<<(long long val)
{
    oss_ << val;
    if (autospace_)
        oss_ << _X(' ');
    return *this;
}

LogStream& LogStream::operator<<(unsigned long long val)
{
    oss_ << val;
    if (autospace_)
        oss_ << _X(' ');
    return *this;
}

LogStream& LogStream::operator<<(float val)
{
    oss_ << val;
    if (autospace_)
        oss_ << _X(' ');
    return *this;
}

LogStream& LogStream::operator<<(double val)
{
    oss_ << val;
    if (autospace_)
        oss_ << _X(' ');
    return *this;
}

LogStream& LogStream::operator<<(long double val)
{
    oss_ << val;
    if (autospace_)
        oss_ << _X(' ');
    return *this;
}

LogStream& LogStream::operator<<(void* val)
{
    oss_ << val;
    if (autospace_)
        oss_ << _X(' ');
    return *this;
}

LogStream& LogStream::operator<<(ostream_type& (*func)(ostream_type&))
{
    oss_ << func;
    return *this;
}

LogStream& LogStream::operator<<(const xCharT* val)
{
    oss_ << val;
    if (autospace_)
        oss_ << _X(' ');
    return *this;
}

LogStream& LogStream::enableAutoSpace()
{
    autospace_ = true;
    return *this;
}

LogStream& LogStream::disableAutoSpace()
{
    autospace_ = false; 
    return *this;
}

LogStream::LogStream(Logger* logger, Log& thislog)
    :logger_(logger),
    thislog_(thislog)
{}

LogStream::LogStream(Logger* logger, const Level* level, const xCharT* func, const xCharT* absfilename, const int lineno)
    :logger_(logger),
    thislog_(level)
{
    if (logger_) 
        thislog_.logger_name_ = logger_->getName().c_str();    
    thislog_.func_name_ = func;
    thislog_.filename_ = SplitFilenameFromFullPath(absfilename);
    thislog_.lineno_ = __LINE__;
}

LogStream::~LogStream()
{
    thislog_.content_ = oss_.str();
    if(logger_)
        logger_->publish(thislog_);
}
NAMESPACE_END
