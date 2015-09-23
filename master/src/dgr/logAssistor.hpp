#ifndef __LOG_ASSISTOR_H__
#define __LOG_ASSISTOR_H__

#include <cstdarg>
#include <direct.h>
#include "level.hpp"
#include "log.hpp"

DGR_NP_BEGIN

typedef Log<DebugLevel> DebugLog;
typedef Log<InfoLevel> InfoLog;
typedef Log<WarnLevel> WarnLog;
typedef Log<ErrLevel> ErrLog;
typedef Log<FatalLevel> FatalLog;

namespace details
{	
	using std::xStrT;	
	inline xStrT ConvertArgsToString(const xCharT* format, ...)
	{
		static const int MAX_BUFFER_SIZE = 300;
		va_list vl;
		va_start(vl, format);
		xCharT buffer[MAX_BUFFER_SIZE] = {_X('\0')};
        xVSprintf_s(buffer, MAX_BUFFER_SIZE - 1, format, vl);
		va_end(vl);
		return xStrT(buffer);
	}

	inline xStrT SplitRelativeFilePath(const xStrT& abs_filepath)
	{
		xCharT* work_dir_buffer = xGetcwd(NULL, 0);
		xStrT substr = abs_filepath.substr(xCsLen(work_dir_buffer));
		free(work_dir_buffer);
		return substr;
	}

	template <class L>
	inline L AssembleLog(const std::xStrT& content,
                                       const xCharT* abs_file,
                                       const xCharT* func,
                                       int lineno)
	{
		typedef L LogType;		
		LogType log(content);
		log.file = SplitRelativeFilePath(abs_file);
		log.func = func;
		log.lineno = lineno;		
		return log;
	}
}

NP_END
#endif