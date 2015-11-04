#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include "dgr2.h"

DGR2_NP_BEGIN
DGR2_API void DebugBreak();
DGR2_API int GetCurrentTickCount();
DGR2_API int GetPresentThreadId();
DGR2_API void Utf8ToWideChar(const char* utf8_chars, wchar_t*& dst_chars, int* dst_buffer_size = NULL);
DGR2_API void WideCharToUtf8(const wchar_t* wide_chars, char*& dst_chars, int* dst_buffer_size = NULL);
class DGR2_API CriticalSectionLock
{
public:
    void lock();
    void unlock();
    CriticalSectionLock();
    ~CriticalSectionLock();
private:
    struct Impl;
    Impl* impl_;
};
NP_END

#endif