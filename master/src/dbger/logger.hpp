#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <sstream>
#include "log.hpp"

DBGER_NP_BEGIN
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
	template <class L>
	void Publish(L& log)
	{		
		if(!Filter(log))		
			return;
		Format(log);
		Write(log);
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
			Destory();
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
		start_flag_ = false;
		if(!Filter(log))		
			return *this;
		Format(log);		
		if(!xstr_stream_)
			xstr_stream_ = new StringstreamT();
		(*xstr_stream_) << log.content;
		start_flag_ = true;
		content_filled_ = false;
		return *this;
	}

	Logger()
		:xstr_stream_(new StringstreamT()),
		start_flag_(false),
		content_filled_(false)
	{}

	~Logger()
	{
		Destory();
	}

private:
	void Destory()
	{
		if(xstr_stream_)		
			delete xstr_stream_;
		xstr_stream_ = NULL;		
		start_flag_ = false;
		content_filled_ = false;
	}
	bool start_flag_;
	bool content_filled_; 	
	typedef std::basic_stringstream<xCharT> StringstreamT;
	StringstreamT* xstr_stream_;
};

DBGER_NP_END
#endif