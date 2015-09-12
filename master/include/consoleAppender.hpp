#ifndef __CONSOLE_APPENDER_H__
#define __CONSOLE_APPENDER_H__

#include <ostream>

DBGER_NP_BEGIN

struct ConsoleAppender
{		
	template <class L>
	void Write(L& log)
	{		
		std::xcout << log.content;
	}

	template <typename T>
 	ConsoleAppender& operator<<(T val)
 	{
 		std::xcout << val;
 		return *this;
 	}
};

DBGER_NP_END
#endif