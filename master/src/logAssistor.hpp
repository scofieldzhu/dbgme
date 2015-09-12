#ifndef __LOG_ASSISTOR_H__
#define __LOG_ASSISTOR_H__

#include <cstdarg>
#include <direct.h>
#include "level.hpp"
#include "log.hpp"

DBGER_NP_BEGIN

typedef Log<DebugLevel> DebugLog;
typedef Log<InfoLevel> InfoLog;
typedef Log<WarnLevel> WarnLog;
typedef Log<ErrLevel> ErrLog;
typedef Log<FatalLevel> FatalLog;

namespace details
{
	using namespace  utils;
	using std::string;
	using std::wstring;
	
 	inline string ConvertArgsToString(const char* format, ...)
 	{
 		static const int MAX_BUFFER_SIZE = 300;
 		va_list vl;
 		va_start(vl, format);
 		char buffer[MAX_BUFFER_SIZE] = {'\0'};
 		vsprintf_s(buffer, MAX_BUFFER_SIZE - 1, format, vl);
 		va_end(vl);
 		return string(buffer);
 	}

	inline wstring ConvertArgsToString(const wchar_t* format, ...)
	{
		static const int MAX_BUFFER_SIZE = 300;
		va_list vl;
		va_start(vl, format);
		wchar_t buffer[MAX_BUFFER_SIZE] = {L'\0'};
		vswprintf_s(buffer, MAX_BUFFER_SIZE - 1, format, vl);
		va_end(vl);
		return wstring(buffer);
	}

	inline string SplitRelativeFilePath(const string& abs_filepath)
	{
		char* work_dir_buffer = _getcwd(NULL, 0);		
		string substr = abs_filepath.substr(strlen(work_dir_buffer));
		free(work_dir_buffer);
		return substr;
	}

	inline wstring SplitRelativeFilePath(const wstring& abs_filepath)
	{
		wchar_t* work_dir_buffer = _wgetcwd(NULL, 0);
		wstring substr = abs_filepath.substr(wcslen(work_dir_buffer));
		free(work_dir_buffer);
		return substr;
	}

	template <class L>
	inline L AssembleLog(const xStrT& content,
									 const xCharT* abs_file,
									 const xCharT* func,
									 int lineno															
									 )
	{
		typedef L LogType;		
		LogType log(content);
		log.file = SplitRelativeFilePath(abs_file);
		log.func = func;
		log.lineno = lineno;		
		return log;
	}
}

DBGER_NP_END
#endif