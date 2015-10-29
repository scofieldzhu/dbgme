#ifndef __CFPDLL_EXPORT_H__
#define __CFPDLL_EXPORT_H__

#ifdef CFP_EXPORTS
#define DGR2_API __declspec(dllexport)
#else
#define DGR2_API __declspec(dllimport)
#endif

#endif