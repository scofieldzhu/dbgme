#include "standardFormatter.h"
#include "log.h"
#include "xtime.h"
#include "xText.h"
#include "level.h"
using namespace std;

DGR2_NP_BEGIN

std::xStrT StandardFormatter::format(const Log& log)
{
    xStrT result = _X("");
    xStrT valid_content = handleLineBreak(log, result);        
    result += _X("[") + log.timestamp_.repr() + _X("]"); 
    result += _X("[") + log.logger_name_ + _X("]");
    result += _X("[");
    result += (log.level_ ? log.level_->repr() : NONE_STR);
    result += _X("]");
    result += _X("[") + Int2Str(log.thread_id_) + _X("]");
    result += _X("[") + log.filename_ + _X("]");    
    result += _X("[") + log.func_name_ + _X("]");    
    result += _X("[") + Int2Str(log.lineno_) + _X("]:");    
    if (!valid_content.empty())
        result += valid_content;
    return result;
}

xStrT StandardFormatter::handleLineBreak(const Log& log, xStrT& formatted_str)
{
    xStrT valid_content = log.content_;
    if(log.content_.empty())
        return valid_content;
    xStrT::size_type pos = 0;    
    for (; pos != xStrT::npos; ++pos)
    {
        if (valid_content[pos] != 13 && valid_content[pos] != 10)
            break;
    }
    if (pos != 0)
    {
        formatted_str = valid_content.substr(0, pos);
        valid_content = valid_content.substr(pos);
    }
    return valid_content;
}

StandardFormatter::StandardFormatter()
{
}

StandardFormatter::~StandardFormatter()
{
}
NP_END