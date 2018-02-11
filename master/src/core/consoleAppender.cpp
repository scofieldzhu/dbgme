#include <iostream>
#include "consoleAppender.h"
using namespace std;

SFLOGGER_NAMESPACE_BEGIN
ConsoleAppender::ConsoleAppender(unsigned int flush_frequence)
    :OstreamAppender(xCout, flush_frequence)
{
}

ConsoleAppender::~ConsoleAppender()
{
}
NAMESPACE_END


