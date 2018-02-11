#include "platform.h"
#if defined(_WIN32) || defined(_WIN64)
#include <intrin.h>
#include <Windows.h>

SFLOGGER_NAMESPACE_BEGIN
SFLOGGER_API void DebugBreak()
{
    __debugbreak();
}

SFLOGGER_API int GetCurrentTickCount()
{
    return ::GetTickCount();
}

SFLOGGER_API int GetPresentThreadId()
{
    return ::GetCurrentThreadId();
}

SFLOGGER_API void Utf8ToWideChar(const char* utf8_chars, wchar_t*& dst_chars, int* dst_buffer_size)
{
    const int kRequiredBufferSize = ::MultiByteToWideChar(CP_UTF8, 0, utf8_chars, -1, NULL, 0);
    wchar_t* buffer = new wchar_t[kRequiredBufferSize];
    int err = ::MultiByteToWideChar(CP_UTF8, 0, utf8_chars, kRequiredBufferSize, buffer, kRequiredBufferSize);
    if (err != 0)
    {
        dst_chars = buffer;
        if (dst_buffer_size)
            *dst_buffer_size = kRequiredBufferSize;
    }
}

SFLOGGER_API void WideCharToUtf8(const wchar_t* wide_chars, char*& dst_chars, int* dst_buffer_size)
{
    const int kRequiredBufferSize = ::WideCharToMultiByte(CP_UTF8, 0, wide_chars, -1, NULL, 0, NULL, NULL);
    char* buffer = new char[kRequiredBufferSize];
    int err = ::WideCharToMultiByte(CP_UTF8, 0, wide_chars, -1, buffer, kRequiredBufferSize, NULL, NULL);
    if (err != 0)
    {
        dst_chars = buffer;
        if (dst_buffer_size)
            *dst_buffer_size = kRequiredBufferSize;
    }
}

struct CriticalSectionLock::Impl
{
    CRITICAL_SECTION cs_;
};

void CriticalSectionLock::lock()
{
    ::EnterCriticalSection(&impl_->cs_);
}

void CriticalSectionLock::unlock()
{
    ::LeaveCriticalSection(&impl_->cs_);
}

CriticalSectionLock::CriticalSectionLock()
    :impl_(new Impl())
{
    InitializeCriticalSection(&impl_->cs_);
}

CriticalSectionLock::~CriticalSectionLock()
{
    ::DeleteCriticalSection(&impl_->cs_);
    delete impl_;
}
NAMESPACE_END

#endif
