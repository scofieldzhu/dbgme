#include "utils.h"
#include <cstdarg>
using namespace std;
DGR2_NP_BEGIN
UTLS_NP_BEGIN

DGR2_API xStrT ConvertArgsToString(const xCharT* format, ...)
{
    static const int MAX_BUFFER_SIZE = 300;
    va_list vl;
    va_start(vl, format);
    xCharT buffer[MAX_BUFFER_SIZE] = { _X('\0') };
    xVSprintf_s(buffer, MAX_BUFFER_SIZE - 1, format, vl);
    va_end(vl);
    return xStrT(buffer);
}

DGR2_API xStrT SplitFilenameFromFullPath(const xCharT* abs_filepath, bool with_ext_flag)
{
    xCharT buffer_fn[256] = { _X('\0') };
    xCharT buffer_ext[20] = { _X('\0') };
    _xsplitpath_s(abs_filepath, NULL, 0, NULL, 0, buffer_fn, 256, buffer_ext, 20);
    return with_ext_flag ? xStrT(buffer_fn) + xStrT(buffer_ext) : xStrT(buffer_ext);
}

NP_END
NP_END
