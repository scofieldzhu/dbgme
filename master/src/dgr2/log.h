#ifndef __LOG_H__
#define __LOG_H__

#include "general.h"
#include "xtime.h"

DGR2_NP_BEGIN

struct DGR2_API Log
{    
//     void setContent(const std::xStrT& content) { content_ = content;  }
//     const std::xStrT& getContent() const { return content_; }
//     const Level& getLevel()const { return *level_;  }
//     const LGT::DateTime& getTimeStamp()const { return timestamp_; }
//     const std::xStrT& getFuncName()const { return func_name_; }
//     const std::xStrT& getFileName()const { return filename_; }
//     int getLineNo()const { return lineno_; }
//     const Log& operator=(const Log& rhs);
//     Log(const Level& level, const std::xStrT& content, const std::xStrT& func_name, const std::xStrT& filename, unsigned int lineno);
//     Log(const Log& rhs);
//     ~Log();
// 
// private:
    Log(const Level& level)
        :level_(&level) 
    {}
    const Level* level_;
    std::xStrT logger_name_;    
    std::xStrT content_;
    std::xStrT func_name_;
    std::xStrT filename_;
    unsigned int lineno_;
    unsigned int thread_id_;
    LGT::DateTime timestamp_;
};

NP_END
#endif