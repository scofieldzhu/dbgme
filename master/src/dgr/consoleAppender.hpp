#ifndef __CONSOLE_APPENDER_H__
#define __CONSOLE_APPENDER_H__

#include <ostream>
#include "basicType.h"

DGR_NP_BEGIN

struct ConsoleAppender
{		
	template <class L>
	void write(L& log)
	{		
		std::xCout << log.content;
	}

	template <typename T>
 	ConsoleAppender& operator<<(T val)
 	{
 		std::xCout << val;
 		return *this;
 	}
};

NP_END
#endif