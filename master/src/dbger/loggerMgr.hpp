#ifndef __LOGGER_MGR_H__
#define __LOGGER_MGR_H__

#include "general.hpp"

DGR_NP_BEGIN

template 
<
	class L,
	class Base	
>
struct LoggerMgr : public Base
{
	using Base::setL;
	using Base::getL;

	void setL(L& logger)
	{
		logger_ = &logger;
	}
		 
	void getL(L* &result)
	{
		result = logger_;
	}
		 
	template <class L>
	void publish(L& log)
	{
		Base::publish(log);
		if(logger_)
		 	logger_->publish(log);
	}

	template <typename T>
	LoggerMgr& operator<<(T val)
	{
		Base::operator<<(val);
		assert(logger_ != NULL);
		(*logger_) << val;
		return *this;
	}
		 
	LoggerMgr()
		:logger_(NULL)
	{}
		 
private:
	L* logger_;
};

template 
<
	class L			
>
struct LoggerMgr<L, NullType>
{
	void setL(L& logger)
	{
		logger_ = &logger;
	}

	void getL(L* &result)
	{
		result = logger_;
	}
	
	template <class L>
	void publish(L& log)
	{		
		if(logger_)
			logger_->publish(log);
	}

	template <typename T>
	LoggerMgr& operator<<(T val)
	{
		assert(logger_ != NULL);
		(*logger_) << val;
		return *this;
	}

	LoggerMgr()
		:logger_(NULL)
	{}

private:
	L* logger_;
};

NP_END
#endif
