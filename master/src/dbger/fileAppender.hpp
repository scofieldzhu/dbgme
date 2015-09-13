#ifndef __FILE_APPENDER_H__
#define __FILE_APPENDER_H__

#include <fstream>
#include "general.hpp"

DBGER_NP_BEGIN
struct FileAppender 
{
	template <class L>
	void Write(L& log)
	{
		if(ofs_.tellp() > MAX_FILE_BYTE_SIZE)		
			ofs_.clear();		
		ofs_ << log.content;
		ofs_.flush();				
	}

	template <typename T>
	FileAppender& operator<<(T val)
	{
		ofs_ << val;
		return *this;
	}

	FileAppender(const std::xStrT& filepath = XT("test.log"))
		:ofs_(filepath, std::ios_base::out | std::ios_base::app)
	{
		assert(!ofs_.bad());			
	}
	~FileAppender()
	{
		ofs_.close();
	}
private:
	static const int MAX_FILE_BYTE_SIZE = 1024 * 1024;
	std::basic_ofstream<xCharT> ofs_;
};
DBGER_NP_END
#endif