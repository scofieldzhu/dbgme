#ifndef __DR2_EXPORTER_H__
#define __DR2_EXPORTER_H__

#ifdef DGR2_EXPORTS
    #define DGR2_API __declspec(dllexport)
#else
    #define DGR2_API __declspec(dllimport)
#endif

#endif