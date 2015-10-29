#ifndef __GENERAL_H__
#define __GENERAL_H__

#include "basicType.h"
#include "dgr2Exporter.h"

#define DGR2 dbger2
#define DGR2_NP_BEGIN NP_BEGIN(DGR2)
#define USING_DGR2 USING_NP(DGR2)

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