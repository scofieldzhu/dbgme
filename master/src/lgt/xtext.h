#ifndef __XTEXT_H__
#define __XTEXT_H__

#include "basicType.h"
#include "lgtDLLExport.h"

LGT_NP_BEGIN
LGT_API std::xStrT Int2Str(int value, int radix = 10);
LGT_API int Str2Int(const std::xStrT& str);
LGT_API std::wstring AnsiToUnicode(const char* src);
LGT_API std::string UnicodeToAnsi(const wchar_t* src);
NP_END
#endif
