#include "xtime.h"
#include <ctime>
#include <sys/timeb.h>
using namespace std;

LGT_NP_BEGIN

DateTime DateTime::Now()
{
    struct _timeb tb_now;
    _ftime_s(&tb_now);
    struct tm tm_now;
    localtime_s(&tm_now, &tb_now.time);
    return DateTime(tm_now.tm_year + 1900,
                                tm_now.tm_mon + 1,
                                tm_now.tm_mday,
                                tm_now.tm_hour,
                                tm_now.tm_min,
                                tm_now.tm_sec,
                                tb_now.millitm);
}

xStrT DateTime::repr() const
{
    static const int MAX_DATETIME_TEXT_BUFFER = 500;
    xCharT buffer[MAX_DATETIME_TEXT_BUFFER] = { XT('\0') };
    xSprintf(buffer,
                  MAX_DATETIME_TEXT_BUFFER - 1,
                  XT("%d/%02d/%02d %02d:%02d:%02d:%03d"),
                  date.year,
                  date.mon,
                  date.mday,
                  daytime.hour,
                  daytime.min,
                  daytime.sec,
                  daytime.millisec);
    return xStrT(buffer);
}

NP_END