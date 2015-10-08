#ifndef __OSTREAM_APPENDER_H__
#define __OSTREAM_APPENDER_H__

#include <ostream>
#include "defAppender.h"

DGR2_NP_BEGIN

struct DGR2_API OstreamAppender : public DefAppender
{    
    void flush();
    virtual ~OstreamAppender();

protected:
    typedef std::basic_ostream<xCharT> OstreamT;
    OstreamAppender(OstreamT& os, unsigned int flush_frequence);
    void write(const std::xStrT& logged_msg);
    OstreamT* os_;
};

NP_END
#endif
