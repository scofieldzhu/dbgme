#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <sstream>
#include "xText.h"
#include "log.hpp"

DGR_NP_BEGIN
struct StreamEndTag{};
struct LineBreakTag{};

template 
<	
	class FilterPolicy,
	class FormatPolicy,	
	class TransferPolicy
>
struct Logger : public FilterPolicy, 
					   public FormatPolicy, 			 			 
					   public TransferPolicy
{		
    typedef FilterPolicy FilterClassType;
    typedef FormatPolicy FormatterClassType;
    typedef TransferPolicy TransferClassType;

    const std::xStrT& getName() { return name_; }

	template <class L>
	void publish(L& log)
	{		
        L* clone_log = log.clone();
        if (filter(*clone_log))
        {
            format(*clone_log);
            appendLoggerInfo(*clone_log);
            write(*clone_log);
        }
        clone_log->destroy();        
	}    

	template <typename T>
	Logger& operator<<(T val)
	{
		if(start_flag_)		
			(*xstr_stream_) << val;		
		return *this;		
	}

	Logger& operator<<(StreamEndTag)
	{
		if(start_flag_)
		{
			start_flag_ = false;				
			TransferPolicy::operator<<(xstr_stream_->str());
			destroy();
		}
		return *this;		
	}

	Logger& operator<<(LineBreakTag)
	{
		if(!start_flag_)		
			return *this;						
		if(content_filled_)				
			(*xstr_stream_) << XT("\r\n");					
		else
		{
			std::xStrT current_content = xstr_stream_->str();			
			xstr_stream_ = new StringstreamT(); //abandon its' content
			(*xstr_stream_) << XT("\r\n");
			(*xstr_stream_) << current_content;			
			content_filled_ = true;
		}									
		return *this;		
	}

	template<class Level>
	Logger& operator<<(Log<Level>& log)
	{
        typedef Log<Level> LogType;
		start_flag_ = false;
        LogType* clone_log = log.clone();
        if (filter(*clone_log))
        {
            format(*clone_log);
            appendLoggerInfo(*clone_log);
            if (!xstr_stream_)
                xstr_stream_ = new StringstreamT();
            (*xstr_stream_) << clone_log->content;
            start_flag_ = true;
            content_filled_ = false;
            return *this;
        }		
        clone_log->destroy();
		return *this;
	}

	Logger(const std::xStrT& name)
		:name_(name),
        xstr_stream_(new StringstreamT()),
		start_flag_(false),
		content_filled_(false),
        total_log_num_(0)
	{}

	~Logger()
	{
		destroy();
	}

private:
    template <class L>
    void appendLoggerInfo(L& log)
    {
        std::xStrT new_content = LGT::Int2Str(total_log_num_);
        new_content += XT(":>[");
        new_content += getName();
        new_content += XT("]");
        new_content += log.content;
        log.content = new_content;
        total_log_num_ += 1;
    }

	void destroy()
	{
		if(xstr_stream_)		
			delete xstr_stream_;
		xstr_stream_ = NULL;		
		start_flag_ = false;
		content_filled_ = false;
	}
    const std::xStrT name_;
    int total_log_num_;
	bool start_flag_;
	bool content_filled_; 	
	typedef std::basic_stringstream<xCharT> StringstreamT;
	StringstreamT* xstr_stream_;
};

NP_END
#endif