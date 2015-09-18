#ifndef __LGTDLL_EXPORT_H__
#define __LGTDLL_EXPORT_H__

#ifdef LGT_EXPORTS
    #define LGT_API __declspec(dllexport)
#else
    #define LGT_API __declspec(dllimport)
#endif

#endif