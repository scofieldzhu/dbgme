#ifndef __BASIC_TYPE_H__
#define __BASIC_TYPE_H__

#include <wchar.h>
#include <cstring>
#include <string>

#ifdef _UNICODE_SUPPORT
    #define _XChar wchar_t
    #define _XT(t) L##t
    #define _xsprintf swprintf_s
    #define __XFUNCTION__  __FUNCTIONW__ 
    #define __XFILE__ __FILEW__
    #define _xcout wcout
#else
    #define _XChar char
    #define _XT(t) t
    #define _xsprintf sprintf_s
    #define __XFUNCTION__  __FUNCTION__ 
    #define __XFILE__ __FILE__
    #define _xcout cout
#endif

#define xChar _XChar
#define XT _XT
#define xsprintf _xsprintf
#define _XFUNCTION_ __XFUNCTION__
#define _XFILE_ __XFILE__
#define xcout _xcout

#endif