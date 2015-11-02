#ifndef __STANDARD_FORMATTER_H__
#define __STANDARD_FORMATTER_H__

#include "formatter.h"

DGR2_NP_BEGIN 
struct DGR2_API StandardFormatter : public Formatter
{
    DGR_OBJECT(StandardFormatter)
    std::xStrT format(const Log& log);
    StandardFormatter();    
private:
    ~StandardFormatter();
    std::xStrT handleLineBreak(const Log& log, std::xStrT& formatted_str);
};
NP_END
#endif
