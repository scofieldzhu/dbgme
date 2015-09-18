#ifndef __LOGGER_MGR_H__
#define __LOGGER_MGR_H__

#include "general.hpp"

DBGER_NP_BEGIN

template 
<
	class L,
	class Base	
>
struct LoggerMgr : public Base
{
	using Base::SetL;
	using Base::GetL;

	void SetL(L& logger)
	{
		logger_ = &logger;
	}
		 
	void GetL(L* &result)
	{
		result = logger_;
	}
		 
	template <class L>
	void Publish(L& log)
	{
		Base::Publish(log);
		if(logger_)
		 	logger_->Publish(log);
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
struct LoggerMgr<L, utils::NullType>
{
	void SetL(L& logger)
	{
		logger_ = &logger;
	}

	void GetL(L* &result)
	{
		result = logger_;
	}
	
	template <class L>
	void Publish(L& log)
	{		
		if(logger_)
			logger_->Publish(log);
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

DBGER_NP_END
#endif
