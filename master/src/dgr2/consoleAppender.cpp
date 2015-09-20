#include <iostream>
#include "consoleAppender.h"
using namespace std;

DGR2_NP_BEGIN
ConsoleAppender::ConsoleAppender(Filter* filter, unsigned int flush_frequence)
    :OstreamAppender(xCout, filter, flush_frequence)
{
}

ConsoleAppender::~ConsoleAppender()
{
}
NP_END


