#include "InoCore.h"
#include "MillisTimer.h"

#include <Arduino.h>

namespace ino {

	MillisTimer::MillisTimer(unsigned int CycleTime) : LastMillis(millis()), CycleTime(CycleTime)
	{}

	bool MillisTimer::Cycle()
	{
		if(millis() - LastMillis >= CycleTime)
		{
			LastMillis = millis();
			return true;
		}
		return false;
	}

	DynamicMillisTimer::DynamicMillisTimer(unsigned int CycleTime) : LastMillis(millis()), CycleTime(CycleTime)
	{}

	bool DynamicMillisTimer::Cycle()
	{
		if(millis() - LastMillis >= CycleTime)
		{
			LastMillis += CycleTime;
			return true;
		}
		return false;
	}

}
