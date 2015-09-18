#ifndef __DR2_DLL_EXPORT_H__
#define __DR2_DLL_EXPORT_H__

#ifdef DBGER2_EXPORTS
    #define DBGER2_API __declspec(dllexport)
#else
    #define DBGER2_API __declspec(dllimport)
#endif

#endif