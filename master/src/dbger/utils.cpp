#include "utils.hpp"
#include "drDLLExport.h"

DBGER_NP_BEGIN
namespace utils {
template <> 
DBGER_API
std::wstring EncodeString<char, wchar_t>(const char* src)
{
	assert(src != NULL);
	size_t return_val = 0;
	mbstowcs_s(&return_val, 0, 0, src, strlen(src));
	wchar_t* dst_buffer = new wchar_t[return_val];
	mbstowcs_s(NULL, dst_buffer, return_val, src, strlen(src));
	std::wstring result =  std::wstring(dst_buffer);
	delete[] dst_buffer;
	return result;
}

template <>
DBGER_API
std::string EncodeString<char, char>(const char* src)
{	
	return std::string(src);
}

template <>
DBGER_API
std::string EncodeString<wchar_t, char>(const wchar_t* src)
{	
	size_t return_val = 0;
	wcstombs_s(&return_val, 0, 0, src, wcslen(src));
	char* dst_buffer = new char[return_val];
	wcstombs_s(NULL, dst_buffer, return_val, src, wcslen(src));
	std::string result =  std::string(dst_buffer);
	delete[] dst_buffer;
	return result;
}

template <>
DBGER_API
std::wstring EncodeString<wchar_t, wchar_t>(const wchar_t* src)
{
	return std::wstring(src);
}

template<>
DBGER_API
std::string IntToStr<char>(int value)
{
	static const int MAX_BIT_NUM = 22;
	char buffer[MAX_BIT_NUM] = {'\0'};
	errno_t result = _itoa_s(value, buffer, MAX_BIT_NUM - 1, 10);
	assert (result == 0);
	return std::string(buffer);
}

template<>
DBGER_API
std::wstring IntToStr<wchar_t>(int value)
{
	static const int MAX_BIT_NUM = 22;
	wchar_t buffer[MAX_BIT_NUM] = {L'\0'};
	errno_t result = _itow_s(value, buffer, MAX_BIT_NUM - 1, 10);
	assert (result == 0);
	return std::wstring(buffer);
}

}//end-utils nps

DBGER_NP_END
