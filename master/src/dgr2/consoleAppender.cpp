#include <iostream>
#include "consoleAppender.h"
using namespace std;

DGR2_NP_BEGIN
ConsoleAppender::ConsoleAppender(unsigned int flush_frequence)
    :OstreamAppender(xCout, flush_frequence)
{
}

ConsoleAppender::~ConsoleAppender()
{
}
NP_END


