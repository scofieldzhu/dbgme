#ifndef __UTILS_H__
#define __UTILS_H__

#include "general.h"
#include "log.h"

DGR2_NP_BEGIN
UTLS_NP_BEGIN
DGR2_API std::xStrT ConvertArgsToString(const xCharT* format, ...);
DGR2_API std::xStrT SplitRelativeFilePath(const xCharT* abs_filepath);
NP_END
NP_END

#endif
