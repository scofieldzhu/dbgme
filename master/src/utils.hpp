#ifndef __XUTILS_H__
#define __XUTILS_H__

#include <ctime>
#include <cstdlib>
#include <cassert>
#include <sys/types.h>
#include <sys/timeb.h>
#include "general.hpp"

DBGER_NP_BEGIN

namespace utils{

struct NullType;

//////////////////////////////////////////////////////////////////////////
//typelist class
//////////////////////////////////////////////////////////////////////////
template 
<
	class T,
	class U
>
struct TypeList
{
	typedef T Head;
	typedef U Tail;
};

namespace typelist{

//////////////////////////////////////////////////////////////////////////
//Make4TypeList struct.
//////////////////////////////////////////////////////////////////////////
template 
<
	typename T1 = NullType,
	typename T2 = NullType,
	typename T3 = NullType,
	typename T4 = NullType	
>
struct Make4TypeList
{
private:
	typedef typename Make4TypeList<T2, T3, T4>::Result TailResult;

public:
	typedef TypeList<T1, TailResult> Result;
};

template <>
struct Make4TypeList<>
{
	typedef NullType Result;
};

//////////////////////////////////////////////////////////////////////////
//Length struct
//////////////////////////////////////////////////////////////////////////
template <class TypeListT> struct Length;

template <>
struct Length<NullType>
{
	enum {Value = 0};
};

template 
<
	class T,
	class U
>
struct Length<TypeList<T, U>>
{	
	enum {Value = 1 + Length<U>::Value};
};

//////////////////////////////////////////////////////////////////////////
//struct TypeAt.
//////////////////////////////////////////////////////////////////////////
template <class TypeListT, unsigned int Index> struct TypeAt;

template 
<
	class Head, 
	class Tail
>
struct TypeAt<TypeList<Head, Tail>, 0>
{
	typedef Head Result;
};

template 
<
	class T, 
	class U, 
	unsigned int Index
>
struct TypeAt<TypeList<T, U>, Index>
{
	typedef typename TypeAt<U, Index - 1>::Result Result;
};

} //end -typelist nps

////////////////////////////////////////////////////////////////////////////////
//WCharChecker class
////////////////////////////////////////////////////////////////////////////////
template <typename CharT>
struct WCharChecker;

template <> 
struct WCharChecker<char>
{
    enum { Result = false };
};

template <> 
struct WCharChecker<wchar_t>
{
    enum { Result = true};
};

/////////////////////////////////////////////////////////////////////////////////
///EqualCharTypeChecker class
///////////////////////////////////////////////////////////////////////////////
template <typename, typename>
struct EqualCharType;

template<>
struct EqualCharType<char, char>
{
	enum {Result = true};
};

template<>
struct EqualCharType<char, wchar_t>
{
	enum {Result = false};
};

template<>
struct EqualCharType<wchar_t, char>
{
	enum {Result = false};
};

template<>
struct EqualCharType<wchar_t, wchar_t>
{
	enum {Result = true};
};

template
<
	typename L,
	typename R
>
struct EqualCharTypeChecker
{
	char array[EqualCharType<L, R>::Result ? 1 : -1];
};

/////////////////////////////////////////////////////////////////////////
//StrType class
/////////////////////////////////////////////////////////////////////////
template <class>
struct CharTraits;

template <>
struct CharTraits<char>
{
	typedef char CharType;
    typedef std::string StringT;    
};

template <>
struct CharTraits<wchar_t>
{
	typedef wchar_t CharType;
    typedef std::wstring StringT;    
};

//////////////////////////////////////////////////////////////////////////
//encode
//////////////////////////////////////////////////////////////////////////
template 
<
	typename SrcCharT,
	typename DstCharT
>
typename CharTraits<DstCharT>::StringT EncodeString(const SrcCharT* src);

//////////////////////////////////////////////////////////////////////////
//itoa
//////////////////////////////////////////////////////////////////////////
template <typename CharT>
typename CharTraits<CharT>::StringT IntToStr(int value);

//////////////////////////////////////////////////////////////////
//datetime 
////////////////////////////////////////////////////////////////////
struct DateTime
{    
	static const int MAX_DATETIME_TEXT_BUFFER = 500;
    static DateTime Now()
    {
        struct _timeb tb_now;
        _ftime_s(&tb_now);		
        struct tm tm_now;
		localtime_s(&tm_now, &tb_now.time);
        return DateTime(tm_now, tb_now.millitm);
    }
    
    void ReprTo(std::string& output)const
    {
        char buffer[MAX_DATETIME_TEXT_BUFFER] = {'\0'};
        sprintf_s(buffer,                     
						MAX_DATETIME_TEXT_BUFFER - 1,
						"%d/%02d/%02d %02d:%02d:%02d:%03d", 
						tm_obj.tm_year + 1900, tm_obj.tm_mon + 1, tm_obj.tm_mday,
						tm_obj.tm_hour, tm_obj.tm_min, tm_obj.tm_sec, milliseconds);
        output = std::string(buffer);                
    }

    void ReprTo(std::wstring& output)const
    {
		wchar_t buffer[MAX_DATETIME_TEXT_BUFFER] = {L'\0'};
		swprintf_s(buffer,      
						   MAX_DATETIME_TEXT_BUFFER - 1,
						   L"%d/%02d/%02d %02d:%02d:%02d:%03d", 
						   tm_obj.tm_year + 1900, tm_obj.tm_mon + 1, tm_obj.tm_mday,
						   tm_obj.tm_hour, tm_obj.tm_min, tm_obj.tm_sec, milliseconds);
		output = std::wstring(buffer);     
    }

    DateTime(const struct tm& tm_val, int msec)
        :tm_obj(tm_val),
        milliseconds(msec){}
    int milliseconds;
    struct tm tm_obj;
};

} //utils nps end

typedef xChar xCharT;
typedef utils::CharTraits<xCharT> xCharTraits;
typedef xCharTraits::StringT xStrT;

DBGER_NP_END

#endif