#ifndef __UTILS_H__
#define __UTILS_H__

#include "general.h"

DGR2_NP_BEGIN
UTLS_NP_BEGIN

DGR2_API std::xStrT ConvertArgsToString(const xCharT* format, ...);

DGR2_API std::xStrT SplitFilenameFromFullPath(const xCharT* abs_filepath, bool with_ext_flag = true);

NP_END
NP_END

#endif
