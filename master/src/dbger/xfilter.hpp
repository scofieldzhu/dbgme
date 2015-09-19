#ifndef __XFILTER_H__
#define __XFILTER_H__

#include "general.hpp"

DGR_NP_BEGIN

struct SwitchFilter
{    
	template <class L>
    bool filter(const L& log)const { return isSwitchOn(); }
    void switchOn(){ switch_ = true;}
    void switchOff(){ switch_ = false;}
    bool isSwitchOn()const { return switch_; }
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
    bool filter(const L& log)const 
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
    bool filter(const L& log)const 
	{		
		return cond_(log); 
	}    
private:
    ConditionType cond_;
};

NP_END

#endif