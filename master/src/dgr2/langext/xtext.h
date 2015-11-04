#ifndef __XTEXT_H__
#define __XTEXT_H__

#include "platform.h"

DGR2_NP_BEGIN
DGR2_API std::xStrT Int2Str(int value, int radix = 10);
DGR2_API int Str2Int(const std::xStrT& str);
DGR2_API std::wstring AnsiToUnicode(const char* src);
DGR2_API std::string UnicodeToAnsi(const wchar_t* src);
DGR2_API std::xStrT ConvertArgsToString(const xCharT* format, ...);
DGR2_API std::xStrT SplitFilenameFromFullPath(const xCharT* abs_filepath, bool with_ext_flag = true);
NP_END
#endif
