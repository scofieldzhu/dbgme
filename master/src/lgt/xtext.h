#ifndef __XTEXT_H__
#define __XTEXT_H__

#include "basicType.h"
#include "lgtDLLExport.h"

LGT_NP_BEGIN
LGT_API std::xStrT Int2Str(int value, int radix = 10);
LGT_API int Str2Int(const std::xStrT& str);
NP_END
#endif
