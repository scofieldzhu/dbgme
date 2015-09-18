#ifndef __XTIME_H__
#define __XTIME_H__

#include "basicType.h"
#include "lgtDLLExport.h"

LGT_NP_BEGIN
struct LGT_API Date
{
    Date(int y = 1900, int m = 1, int d = 1)
        :year(y),
        mon(m),
        mday(d)
    {}
    int year;
    int mon;
    int mday;
};

struct LGT_API DayTime
{
    DayTime(int h = 0, int m = 0, int s = 0, int ms = 0)
        :hour(h),
        min(m),
        sec(s),
        millisec(ms)
    {}
    int hour;
    int min;
    int sec;
    int millisec;
};

struct LGT_API DateTime
{
    static DateTime Now();
    void ReprTo(std::xStrT& output)const;
    DateTime()
    {}
    DateTime(const Date& d, const DayTime& t)
        :date(d),
        daytime(t)
    {}
    DateTime(int y, int m, int d, int h, int min, int s, int ms)
        :date(y, m, d),
        daytime(h, min, s, ms)
    {}
    ~DateTime()
    {}
    Date date;
    DayTime daytime;
};
NP_END

#endif