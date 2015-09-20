#ifndef __EXPORT_MACRO_H__
#define __EXPORT_MACRO_H__

#ifdef DGR_EXPORTS
    #define DGR_API __declspec(dllexport)
#else
    #define DGR_API __declspec(dllimport)
#endif

#endif
