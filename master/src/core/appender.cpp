#include "appender.h"
#include "filter.h"
#include "formatter.h"

SFLOGGER_NAMESPACE_BEGIN
void Appender::destroy()
{
    if (getFilter())
        getFilter()->destroy();
    setFilter(NULL);
    if (getFormatter())
        getFormatter()->destroy();
    setFormatter(NULL);
    HeapObject::destroy();
}
NAMESPACE_END