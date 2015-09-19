#ifndef __LOG_H__
#define __LOG_H__

#include "xtime.h"

DGR_NP_BEGIN

template <class Level>
struct Log
{    
    typedef Level LevelType;    

    Log(const std::xStrT& content_val)
        :content(content_val),
		timestamp(LGT::DateTime::Now())
	{}    

	Log(const std::xStrT& content_val, const std::xStrT& func_val, const std::xStrT& file_val, int lineno_val)
		:content(content_val),
		func(func_val),
		file(file_val),
		lineno(lineno_val),
		timestamp(LGT::DateTime::Now())
	{}

    Log* clone()
    {
        Log* copy = new Log(content);
        *copy = *this;
        return copy;
    }

    void destroy()
    {
        delete this;
    }    

    std::xStrT content;
    std::xStrT func;
    std::xStrT file;
    int lineno;
	LGT::DateTime timestamp;    
};

NP_END

#endif