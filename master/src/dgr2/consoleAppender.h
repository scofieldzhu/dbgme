#ifndef __CONSOLE_APPENDER_H__
#define __CONSOLE_APPENDER_H__

#include "ostreamAppender.h"

DGR2_NP_BEGIN
struct DGR2_API ConsoleAppender : public OstreamAppender
{
    ConsoleAppender(Filter* filter, unsigned int flush_frequence);
    ~ConsoleAppender();
};
NP_END
#endif
