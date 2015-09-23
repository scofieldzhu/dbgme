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

DGR2_API xStrT SplitRelativeFilePath(const xCharT* abs_filepath)
{
    xCharT* work_dir_buffer = xGetcwd(NULL, 0);    
    xStrT substr = xStrT(abs_filepath).substr(xCsLen(work_dir_buffer));
    free(work_dir_buffer);
    return substr;
}

NP_END
NP_END
