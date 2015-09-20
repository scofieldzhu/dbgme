#ifndef __GENERAL_H__
#define __GENERAL_H__

#include "basicType.h"

#define DGR2 dbger2
#define DGR2_NP_BEGIN NP_BEGIN(DGR2)
#define USING_DGR2 USING_NP(DGR2)

#define UTLS utils
#define UTLS_NP_BEGIN NP_BEGIN(UTLS)
#define USING_UTLS USING_NP(UTLS)

DGR2_NP_BEGIN

struct Level;
struct Log;

NP_END
#endif