#include "standardFormatter.h"
#include "log.h"
#include "xtime.h"
#include "xText.h"
#include "level.h"
using namespace std;
USING_LGT

DGR2_NP_BEGIN

void StandardFormatter::format(Log& log)
{
    xStrT result = _X("");
    handleLineBreak(log, result);
    result += _X("[");    
    result += log.timestamp_.repr();
    result += _X("][");
    if(log.level_)
        result += log.level_->repr();
    else
        result += NONE_STR;
    result += _X("][");
    result += log.filename_;
    result += _X("(");
    result += Int2Str(log.lineno_);    
    result += _X(")]:");
    if (!log.content_.empty())
        result += log.content_;
    log.content_ = result;
}

void StandardFormatter::handleLineBreak(Log& log, xStrT& formatted_str)
{
    if(log.content_.empty())
        return;
    xStrT::size_type pos = 0;
    xStrT content_copy = log.content_;
    for (; pos != xStrT::npos; ++pos)
    {
        if (content_copy[pos] != 13 && content_copy[pos] != 10)
            break;
    }
    if (pos != 0)
    {
        formatted_str = content_copy.substr(0, pos);
        log.content_ = content_copy.substr(pos);
    }
}

StandardFormatter::StandardFormatter()
{
}

StandardFormatter::~StandardFormatter()
{
}
NP_END