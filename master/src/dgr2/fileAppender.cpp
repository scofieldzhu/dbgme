#include "fileAppender.h"
#include <fstream>
using namespace std;

DGR2_NP_BEGIN
typedef std::basic_ofstream<xCharT> FStreamT;

FileAppender::FileAppender(const std::xStrT& filepath, Filter* filter, unsigned int flush_frequence)
    :OstreamAppender(*(new FStreamT(filepath.c_str(), std::ios::app)), filter, flush_frequence)
{
}

FileAppender::~FileAppender()
{    
    delete os_;
}
NP_END