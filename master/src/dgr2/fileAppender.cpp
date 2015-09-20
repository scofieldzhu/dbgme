#include "fileAppender.h"
#include <fstream>
using namespace std;

DGR2_NP_BEGIN
FileAppender::FileAppender(const std::xStrT& filepath, Filter* filter, unsigned int flush_frequence)
    :ofs_(new FStreamT(filepath.c_str(), std::ios::app)),
    OstreamAppender(*ofs_, filter, flush_frequence)
{
}

FileAppender::~FileAppender()
{
    delete ofs_;
}
NP_END