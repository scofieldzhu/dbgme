#ifndef __XFILTER_H__
#define __XFILTER_H__

#include "general.hpp"

DBGER_NP_BEGIN

struct SwitchFilter
{    
	template <class L>
    bool Filter(const L& log)const { return IsSwitchOn(); }
    void SwitchOn(){ switch_ = true;}
    void SwitchOff(){ switch_ = false;}
    bool IsSwitchOn()const { return switch_; }
    SwitchFilter(bool on = true)
        :switch_(on){}
private:
    bool switch_;
};

template <class FixedLevel>
struct LevelFilter
{    
    typedef FixedLevel LeftLevelType;    

	template <class L>
    bool Filter(const L& log)const 
	{ 
		typedef L LogType;
		typedef typename LogType::LevelType RightLevelType;
		return RightLevelType::GetLevelVal() >= LeftLevelType::GetLevelVal(); 
	}    
};

template <class Condition>    
struct ConditionFilter
{    
    typedef Condition ConditionType;    

	template <class L>
    bool Filter(const L& log)const 
	{		
		return cond_(log); 
	}    
private:
    ConditionType cond_;
};

DBGER_NP_END

#endif