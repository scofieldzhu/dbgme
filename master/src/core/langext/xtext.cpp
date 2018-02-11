#include "xtext.h"
#include <tchar.h>
#include <cassert>
#include <cstdarg>
using namespace std;

SFLOGGER_NAMESPACE_BEGIN

SFLOGGER_API xStrT Int2Str(int value, int radix)
{
     static const int MAX_BUFFER_SIZE = 30;
     xCharT buffer[MAX_BUFFER_SIZE] = { _X('\0') };
     errno_t result = _itot_s(value, buffer, MAX_BUFFER_SIZE - 1, 10);
     assert(result == 0);
     return xStrT(buffer);
}

SFLOGGER_API int Str2Int(const xStrT& str)
{
    return _tstoi(str.c_str());
}

SFLOGGER_API std::wstring AnsiToUnicode(const char* src)
{
    size_t required_buffer_size = 0;
    mbstowcs_s(&required_buffer_size, NULL, 0, src, 0);
    wchar_t* buffer = new wchar_t[required_buffer_size + 1]; 
    memset(buffer, 0, required_buffer_size + 1);
    size_t return_value = 0;
    mbstowcs_s(&return_value, buffer, required_buffer_size + 1, src, required_buffer_size);
    return buffer;
}

SFLOGGER_API std::string UnicodeToAnsi(const wchar_t* src)
{
    size_t required_buffer_size = 0;
    wcstombs_s(&required_buffer_size, NULL, 0, src, 0);
    char* buffer = new char[required_buffer_size + 1];
    memset(buffer, 0, required_buffer_size + 1);
    size_t return_value = 0;
    wcstombs_s(&return_value, buffer, required_buffer_size + 1, src, required_buffer_size);
    return buffer;
}

SFLOGGER_API xStrT ConvertArgsToString(const xCharT* format, ...)
{
    static const int MAX_BUFFER_SIZE = 300;
    va_list vl;
    va_start(vl, format);
    xCharT buffer[MAX_BUFFER_SIZE] = { _X('\0') };
    xVSprintf_s(buffer, MAX_BUFFER_SIZE - 1, format, vl);
    va_end(vl);
    return xStrT(buffer);
}

SFLOGGER_API xStrT SplitFilenameFromFullPath(const xCharT* abs_filepath, bool with_ext_flag)
{
    xCharT buffer_fn[256] = { _X('\0') };
    xCharT buffer_ext[20] = { _X('\0') };
    _xsplitpath_s(abs_filepath, NULL, 0, NULL, 0, buffer_fn, 256, buffer_ext, 20);
    return with_ext_flag ? xStrT(buffer_fn) + xStrT(buffer_ext) : xStrT(buffer_ext);
}
NAMESPACE_END
