#ifndef __CONSOLE_APPENDER_H__
#define __CONSOLE_APPENDER_H__

#include "ostreamAppender.h"

DGR2_NP_BEGIN
struct DGR2_API ConsoleAppender : public OstreamAppender
{
    ConsoleAppender(unsigned int flush_frequence = 1);
    ~ConsoleAppender();
};
NP_END
#endif
