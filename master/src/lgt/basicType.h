#ifndef __BASIC_TYPE_H__
#define __BASIC_TYPE_H__

#include <wchar.h>
#include <cstring>
#include <string>
#include <memory>

#ifdef _UNICODE
    #define _XChar wchar_t
    #define __X(t) L##t
    #define _xstring wstring
    #define _xCsLen wcslen
    #define _xsprintf swprintf_s
    #define _xvsprintf_s vswprintf_s
    #define __XFUNCTION__  __FUNCTIONW__ 
    #define __XFILE__ __FILEW__
    #define _xgetcwd _wgetcwd
    #define _xcout wcout
#else
    #define _XChar char
    #define __X(t) t
    #define _xstring string
    #define _xCsLen strlen
    #define _xsprintf sprintf_s
    #define _xvsprintf_s vsprintf_s
    #define __XFUNCTION__  __FUNCTION__ 
    #define __XFILE__ __FILE__
    #define _xgetcwd _getcwd
    #define _xcout cout
#endif

#define xCharT _XChar
#define _X __X
#define xStrT _xstring
#define xCsLen _xCsLen
#define xSprintf _xsprintf
#define xVSprintf_s _xvsprintf_s
#define _XFUNCTION_ __XFUNCTION__
#define _XFILE_ __XFILE__
#define xGetcwd _xgetcwd
#define xCout _xcout

#define NP_BEGIN(np) namespace np{
#define NP_END }
#define USING_NP(np) using namespace np;

#define LGT lgt
#define LGT_NP_BEGIN NP_BEGIN(LGT)
#define USING_LGT USING_NP(LGT)

#pragma warning(disable:4251)

#endif