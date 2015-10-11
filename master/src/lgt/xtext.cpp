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

LGT_API std::wstring AnsiToUnicode(const char* src)
{
    size_t required_buffer_size = 0;
    mbstowcs_s(&required_buffer_size, NULL, 0, src, 0);
    wchar_t* buffer = new wchar_t[required_buffer_size + 1]; 
    memset(buffer, 0, required_buffer_size + 1);
    size_t return_value = 0;
    mbstowcs_s(&return_value, buffer, required_buffer_size + 1, src, required_buffer_size);
    return buffer;
}

LGT_API std::string UnicodeToAnsi(const wchar_t* src)
{
    size_t required_buffer_size = 0;
    wcstombs_s(&required_buffer_size, NULL, 0, src, 0);
    char* buffer = new char[required_buffer_size + 1];
    memset(buffer, 0, required_buffer_size + 1);
    size_t return_value = 0;
    wcstombs_s(&return_value, buffer, required_buffer_size + 1, src, required_buffer_size);
    return buffer;
}

NP_END
