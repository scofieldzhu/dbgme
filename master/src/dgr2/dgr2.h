#ifndef __GENERAL_H__
#define __GENERAL_H__

#include "langext.h"
#include "dr2DllExport.h"

#define DGR2 dbger2
#define DGR2_NP_BEGIN NP_BEGIN(DGR2)
#define USING_DGR2 USING_NP(DGR2)

#define UTLS utils
#define UTLS_NP_BEGIN NP_BEGIN(UTLS)
#define USING_UTLS USING_NP(UTLS)

DGR2_NP_BEGIN
struct DGRObject;
struct Level;
struct Log;
struct Filter;
struct Appender;
struct Formatter;
struct Logger;
NP_END
#endif