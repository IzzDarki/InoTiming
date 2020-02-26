#pragma once
#ifndef INO_MICROSTIMER_INCLUDED
#define INO_MICROSTIMER_INCLUDED

#include "InoCore.h"

namespace ino {

	class MicrosTimer //repeating rate remains stable, member function Cycle() returns true only when given time has passed since it's last call
	{
	protected:
		unsigned long LastMicros;
		unsigned int CycleTime;
	
	public:
		MicrosTimer(unsigned int CycleTime = 0);

		inline void SetCycle(unsigned int NewCycleTime) { CycleTime = NewCycleTime; }

		bool Cycle();
	
	};

	class DynamicMicrosTimer //repeating rate is dynamic, if more time than given has passed between 2 calls to member function Cycle(), the lost time will be made up again in further calls to Cycle()
	{
	protected:
		unsigned long LastMicros;
		unsigned int CycleTime;
	
	public:
		DynamicMicrosTimer(unsigned int CycleTime = 0);

		inline void SetCycle(unsigned int NewCycleTime) { CycleTime = NewCycleTime; }

		bool Cycle();
	
	};

}

#endif