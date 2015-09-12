#ifndef __EXPORT_MACRO_H__
#define __EXPORT_MACRO_H__

#ifdef DBGER_EXPORTS
    #define DBGER_API __declspec(dllexport)
#else
    #define DBGER_API __declspec(dllimport)
#endif

#endif
