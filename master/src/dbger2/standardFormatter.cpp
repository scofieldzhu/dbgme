#include "standardFormatter.h"
#include "log.h"
#include "xtime.h"
#include "xText.h"
#include "level.h"
using namespace std;
USING_DGR2
USING_LGT

void StandardFormatter::Format(Log& log)
{
    xStrT result = XT("");
    HandleLineBreak(log, result);
    result += XT("[");
    xStrT timestamp_desp;
    log.GetDateTimeStamp().ReprTo(timestamp_desp);
    result += timestamp_desp;
    result += XT("][");
    result += log.GetLevel().Repr();
    result += XT("][");
    result += log.GetFileName();
    result += XT("(");
    result += Int2Str(log.GetLineNo());
    result += XT(")]:");
    if (!log.GetContent().empty())
        result += log.GetContent();
    log.SetContent(result);
}

void StandardFormatter::HandleLineBreak(Log& log, xStrT& formatted_str)
{
    if (log.GetContent().empty())
        return;
    xStrT::size_type pos = 0;
    xStrT content_copy = log.GetContent();
    for (; pos != std::xStrT::npos; ++pos)
    {
        if (content_copy[pos] != 13 && content_copy[pos] != 10)
            break;
    }
    if (pos != 0)
    {
        formatted_str = content_copy.substr(0, pos);
        log.SetContent(content_copy.substr(pos));
    }
}

StandardFormatter::StandardFormatter()
{

}

StandardFormatter::~StandardFormatter()
{

}
