#include "fileAppender.h"
#include <fstream>
using namespace std;

SFLOGGER_NAMESPACE_BEGIN
typedef std::basic_ofstream<xCharT> FStreamT;

FileAppender::FileAppender(const std::xStrT& filepath, unsigned int flush_frequence)
    :OstreamAppender(*(new FStreamT(filepath.c_str(), std::ios::app)), flush_frequence)
{
}

FileAppender::~FileAppender()
{    
    delete os_;
}
NAMESPACE_END