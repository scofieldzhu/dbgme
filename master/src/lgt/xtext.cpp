#include <tchar.h>
#include <cassert>
#include "xtext.h"
using namespace std;

LGT_NP_BEGIN

LGT_API xStrT Int2Str(int value, int radix)
{
     static const int MAX_BUFFER_SIZE = 30;
     xCharT buffer[MAX_BUFFER_SIZE] = { _X('\0') };
     errno_t result = _itot_s(value, buffer, MAX_BUFFER_SIZE - 1, 10);
     assert(result == 0);
     return xStrT(buffer);
}

LGT_API int Str2Int(const xStrT& str)
{
    return _tstoi(str.c_str());
}
NP_END
