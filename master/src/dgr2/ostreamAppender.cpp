#include "ostreamAppender.h"
#include "xtext.h"
#include "log.h"
using namespace std;

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

void OstreamAppender::write(const Log& log, const std::xStrT& logged_msg)
{
    os_->write(logged_msg.c_str(), logged_msg.size()); 
}

NP_END