#include "utils.h"
#include <cstdarg>
using namespace std;
DGR2_NP_BEGIN
UTLS_NP_BEGIN

xStrT ConvertArgsToString(const xCharT* format, ...)
{
    static const int MAX_BUFFER_SIZE = 300;
    va_list vl;
    va_start(vl, format);
    xCharT buffer[MAX_BUFFER_SIZE] = { XT('\0') };
    xVSprintf_s(buffer, MAX_BUFFER_SIZE - 1, format, vl);
    va_end(vl);
    return xStrT(buffer);
}
NP_END
NP_END
