#include "tracer.h"
#include "log.h"
#include "levels.h"
#include "xtext.h"
#include "logger.h"
#include "platform.h"
using namespace std;

SFLOGGER_NAMESPACE_BEGIN

namespace {   
    int g_track_start_tickcount = 0;
    int g_last_track_slot_tickcount = 0;
    Logger* g_track_logger = NULL;
}

SFLOGGER_API void StartTrack(Logger& logger, xCharT* file, const xCharT* function, int lineno)
{
    g_track_start_tickcount = GetCurrentTickCount();
    g_last_track_slot_tickcount = g_track_start_tickcount;
    g_track_logger = &logger;    
    InfoLevel info_level;
    g_track_logger->publish(info_level, file, function, lineno, _X("Start New Tracker...\r\n"));
}

SFLOGGER_API void StopTrack(const xCharT* file, const xCharT* function, int lineno)
{
    const int kNowTickTime = GetCurrentTickCount();
    const int kTotalCostTime = kNowTickTime - g_track_start_tickcount;
    const int kOffsetCostTime = kNowTickTime - g_last_track_slot_tickcount;
    InfoLevel info_level;
    g_track_logger->publish(info_level, file, function, lineno, _X("Tracker Stopped![total cost time:%d ms offset time:%d ms]\r\n"), kTotalCostTime, kOffsetCostTime);
    g_track_start_tickcount = 0;
    g_last_track_slot_tickcount = 0;
    g_track_logger = NULL;
}

SFLOGGER_API void PlaceTrackSlot(const xCharT* file, const xCharT* function, int lineno)
{    
    const int kNowTickTime = GetCurrentTickCount();
    const int kTotalCostTime = kNowTickTime - g_track_start_tickcount;
    const int kOffsetCostTime = kNowTickTime - g_last_track_slot_tickcount;
    InfoLevel info_level;
    g_track_logger->publish(info_level, file, function, lineno, _X("New Track Slot Placed![total cost time:%d ms offset time:%d ms]\r\n"), kTotalCostTime, kOffsetCostTime);
    g_last_track_slot_tickcount = kNowTickTime;
}

struct FunctionTracer::Impl 
{
    Impl(Logger& logger, const Level& level, const xCharT* file, const xCharT* function, int lineno, bool trace_time_wasted);
    ~Impl();
    Log log_;
    bool trace_time_wasted_;
    Logger* logger_;
    const int start_time_;
};

FunctionTracer::Impl::Impl(Logger& logger, const Level& level, const xCharT* file, const xCharT* function, int lineno, bool trace_time_wasted)
    :log_(level),
    trace_time_wasted_(trace_time_wasted),
    logger_(&logger),
    start_time_(GetCurrentTickCount())
{
    log_.func_name_ = function;
    log_.filename_ = SplitFilenameFromFullPath(file);
    log_.lineno_ = lineno;
    xCharT content_buffer[200] = { _X('\0') };
    xSprintf(content_buffer, 200, _X("%s FunctionTracer start..\r\n"), function);
    log_.content_ = content_buffer;
    logger_->publish(log_);
}

FunctionTracer::Impl::~Impl()
{
    log_.lineno_ = -1;
    xCharT content_buffer[200] = { _X('\0') };
    if(!trace_time_wasted_)
        xSprintf(content_buffer, 200, _X("%s FunctionTracer End..\r\n"), log_.func_name_.c_str());
    else
        xSprintf(content_buffer, 200, _X("%s FunctionTracer End[waste time:%d ms]..\r\n"), log_.func_name_.c_str(), GetCurrentTickCount() - start_time_);
    log_.content_ = content_buffer;
    logger_->publish(log_);
}

FunctionTracer::FunctionTracer(Logger& logger, const xCharT* file, const xCharT* function, int lineno, bool trace_time_wasted)
    :impl_(new Impl(logger, InfoLevel(), file, function, lineno, trace_time_wasted))    
{    
}

FunctionTracer::~FunctionTracer()
{
    delete impl_;
}
NAMESPACE_END



