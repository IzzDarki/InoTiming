#include "InoCore.h"
#include "MicrosTimer.h"

#include <Arduino.h>

namespace ino {
	
	MicrosTimer::MicrosTimer(unsigned int CycleTime) : LastMicros(micros()), CycleTime(CycleTime)
	{}

	bool MicrosTimer::Cycle()
	{
		if(micros() - LastMicros >= CycleTime)
		{
			LastMicros = micros();
			return true;
		}
		return false;
	}

	DynamicMicrosTimer::DynamicMicrosTimer(unsigned int CycleTime) : LastMicros(micros()), CycleTime(CycleTime)
	{}

	bool DynamicMicrosTimer::Cycle()
	{
		if(micros() - LastMicros >= CycleTime)
		{
			LastMicros += CycleTime;
			return true;
		}
		return false;
	}

}
