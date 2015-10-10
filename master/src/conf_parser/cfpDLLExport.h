#ifndef __CFPDLL_EXPORT_H__
#define __CFPDLL_EXPORT_H__

#ifdef CFP_EXPORTS
#define CFP_API __declspec(dllexport)
#else
#define CFP_API __declspec(dllimport)
#endif

#endif