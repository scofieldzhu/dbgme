#ifndef __GENERAL_H__
#define __GENERAL_H__

#include "langext.h"

#define DBGER2 dbger2
#define DBGER2_NP_BEGIN namespace DBGER2 {
#define DBGER2_NP_END }
#define USING_DBGER2 using namespace DBGER2;

#define UTILS utils
#define UTILS_NP_BEGIN namespace UTILS {
#define UTILS_NP_END }
#define USING_UTILS using namespace UTILS;

DBGER2_NP_BEGIN
struct Level;
struct Log;
UTILS_NP_BEGIN
struct DateTime;
UTILS_NP_END
DBGER2_NP_END

#endif