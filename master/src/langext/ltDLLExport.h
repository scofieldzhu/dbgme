#ifndef __LTDLL_EXPORT_H__
#define __LTDLL_EXPORT_H__

#ifdef LANGEXT_EXPORTS
    #define LANGEXT_API __declspec(dllexport)
#else
    #define LANGEXT_API __declspec(dllimport)
#endif

#endif