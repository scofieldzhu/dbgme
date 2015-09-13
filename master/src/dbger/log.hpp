#ifndef __LOG_H__
#define __LOG_H__

#include "utils.hpp"

DBGER_NP_BEGIN

template <class Level>
struct Log
{    
    typedef Level LevelType;    

    Log(const std::xStrT& content_val)
        :content(content_val),
		timestamp(utils::DateTime::Now())
	{}    

	Log(const std::xStrT& content_val, const std::xStrT& func_val, const std::xStrT& file_val, int lineno_val)
		:content(content_val),
		func(func_val),
		file(file_val),
		lineno(lineno_val),
		timestamp(utils::DateTime::Now())
	{}

    Log* Clone()
    {
        Log* clone = new Log(content);
        *clone = *this;
        return clone;
    }

    void Destroy()
    {
        delete this;
    }    

    std::xStrT content;
    std::xStrT func;
    std::xStrT file;
    int lineno;
	utils::DateTime timestamp;    
};

DBGER_NP_END

#endif