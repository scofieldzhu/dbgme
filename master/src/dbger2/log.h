#ifndef __LOG_H__
#define __LOG_H__

#include "dr2DllExport.h"
#include "general.h"
#include "xtime.h"

DGR2_NP_BEGIN

struct DGR2_API Log
{    
    void SetContent(const std::xStrT& content) { content_ = content;  }
    const std::xStrT& GetContent() { return content_; }
    const Level& GetLevel()const { return *level_;  }
    const LGT::DateTime& GetDateTimeStamp()const { return timestamp_; }
    const std::xStrT& GetFuncName()const { return func_name_; }
    const std::xStrT& GetFileName()const { return filename_; }
    int GetLineNo()const { return lineno_; }
    const Log& operator=(const Log& rhs);
    Log(const Level& level, const std::xStrT& content, const std::xStrT& func_name, const std::xStrT& filename, int lineno);
    ~Log();

private:
    Level* level_;
    std::xStrT content_;
    std::xStrT func_name_;
    std::xStrT filename_;
    int lineno_;
    LGT::DateTime timestamp_;
};

NP_END
#endif