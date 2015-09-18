#include <tchar.h>
#include <cassert>
#include "xText.h"
using namespace std;
USING_LGT

xStrT Int2Str(int value, int radix)
{
    static const int MAX_BUFFER_SIZE = 30;
    xCharT buffer[MAX_BUFFER_SIZE] = { XT('\0') };
    errno_t result = _itot_s(value, buffer, MAX_BUFFER_SIZE - 1, 10);
    assert(result == 0);
    return xStrT(buffer);
}

int Str2Int(const xStrT& str)
{
    return _tstoi(str.c_str());
}
