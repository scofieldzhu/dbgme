#include "ostreamAppender.h"
#include "xtext.h"
#include "log.h"
using namespace std;
USING_LGT

DGR2_NP_BEGIN
OstreamAppender::OstreamAppender(OstreamT& os, Filter* filter, unsigned int flush_frequence)
    :DefAppender(filter, flush_frequence),
    os_(&os)
{
}

OstreamAppender::~OstreamAppender()
{
}

void OstreamAppender::flush()
{
    os_->flush();
}

void OstreamAppender::doWrite(const Log& log)
{
    xStrT content = Int2Str(getFinishedLogCount());
    content += _X(">");
    content += log.content_;
    os_->write(content.c_str(), content.size());    
}

NP_END