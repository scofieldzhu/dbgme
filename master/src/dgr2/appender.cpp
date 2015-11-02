#include "appender.h"
#include "filter.h"
#include "formatter.h"

DGR2_NP_BEGIN
void Appender::destroy()
{
    if (getFilter())
        getFilter()->destroy();
    setFilter(NULL);
    if (getFormatter())
        getFormatter()->destroy();
    setFormatter(NULL);
    DGRObject::destroy();
}
NP_END