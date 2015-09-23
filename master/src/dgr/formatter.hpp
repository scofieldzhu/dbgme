#ifndef __FORMATTER_H__
#define __FORMATTER_H__

#include "general.hpp"
#include "xText.h"

DGR_NP_BEGIN

struct SimpleFormatter
{	
	template <class LogType>
    void format(LogType& log)
    {				
		typedef typename LogType::LevelType LevelType;				
		std::xStrT result = _X("");
		handleLineBreak(log, result);
		result += _X("[");		
        result += log.timestamp.repr();
		result += _X("][");
		result += std::xStrT(LevelType::GetDesp());
		result += _X("][");
		result += log.file;
		result += _X("(");
        result += LGT::Int2Str(log.lineno);
		result += _X(")]:");		
		if(!log.content.empty())
			result += log.content;
        log.content = result;
    }

private:
	template <class LogType>
	void handleLineBreak(LogType& log, std::xStrT& formatted_str)
	{		
		if(log.content.empty())		
			return;		
		std::xStrT::size_type pos = 0;
		for(; pos != std::xStrT::npos; ++pos)
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

NP_END

#endif