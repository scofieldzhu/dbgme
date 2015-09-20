#ifndef __FILE_APPENDER_H__
#define __FILE_APPENDER_H__

#include <fstream>
#include "ostreamAppender.h"

DGR2_NP_BEGIN
struct DGR2_API FileAppender : public OstreamAppender
{
    FileAppender(const std::xStrT& filepath, Filter* filter, unsigned int flush_frequence);
    ~FileAppender();
private:
    typedef std::basic_ofstream<xCharT> FStreamT;
    FStreamT* ofs_;
};
NP_END
#endif
