#ifndef __FORMATTER_H__
#define __FORMATTER_H__

#include "utils.hpp"

DBGER_NP_BEGIN

struct SimpleFormatter
{	
	template <class LogType>
    void Format(LogType& log)
    {				
		typedef typename LogType::LevelType LevelType;				
		xStrT result = XT("");
		HandleLineBreak(log, result);
		result += XT(">[");
		xStrT timestamp_str;
		log.timestamp.ReprTo(timestamp_str);
		result += timestamp_str;
		result += XT("][");
		result += utils::EncodeString<char, xCharT>(LevelType::GetDesp());
		result += XT("][");
		result += log.file;
		result += XT("(");
		result += utils::IntToStr<xCharT>(log.lineno);
		result += XT(")]:");		
		if(!log.content.empty())
			result += log.content;
        log.content = result;
    }

private:
	template <class LogType>
	void HandleLineBreak(LogType& log, xStrT& formatted_str)
	{		
		if(log.content.empty())		
			return;		
		xStrT::size_type pos = 0;
		for(; pos != xStrT::npos; ++pos)
		{
			if(log.content[pos] != 13 && log.content[pos] != 10)
				break;
		}
		if(pos != 0)
		{
			formatted_str = log.content.substr(0, pos);
			log.content = log.content.substr(pos);
		}		
	}
};

DBGER_NP_END

#endif