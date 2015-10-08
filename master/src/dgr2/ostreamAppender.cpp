#include "ostreamAppender.h"
#include "xtext.h"
#include "log.h"
using namespace std;
USING_LGT

DGR2_NP_BEGIN
OstreamAppender::OstreamAppender(OstreamT& os, unsigned int flush_frequence)
    :DefAppender(flush_frequence),
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

void OstreamAppender::write(const std::xStrT& logged_msg)
{
//     xStrT content = Int2Str(getFinishedLogCount());
//     content += _X(">");
//     content += log.content_;
    os_->write(logged_msg.c_str(), logged_msg.size() * sizeof(xCharT));
}

NP_END