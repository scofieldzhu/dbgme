#ifndef __STANDARD_FORMATTER_H__
#define __STANDARD_FORMATTER_H__

#include "formatter.h"

DGR2_NP_BEGIN 
struct DGR2_API StandardFormatter : public Formatter
{
    void Format(Log& log);
    StandardFormatter();
    ~StandardFormatter();
private:
    void HandleLineBreak(Log& log, std::xStrT& formatted_str);
};
NP_END
#endif
