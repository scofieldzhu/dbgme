#ifndef __FILE_APPENDER_H__
#define __FILE_APPENDER_H__

#include "ostreamAppender.h"

DGR2_NP_BEGIN
struct DGR2_API FileAppender : public OstreamAppender
{
    FileAppender(const std::xStrT& filepath, unsigned int flush_frequence);
    ~FileAppender();
};
NP_END
#endif
