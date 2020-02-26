#pragma once
#ifndef INO_MILLISTIMER_INCLUDED
#define INO_MILLISTIMER_INCLUDED

#include "InoCore.h"

namespace ino {

	class MillisTimer //repeating rate remains stable, member function Cycle() returns true only when given time has passed since it's last call
	{
	protected:
		unsigned long LastMillis;
		unsigned int CycleTime;
	
	public:
		MillisTimer(unsigned int CycleTime = 0);

		inline void SetCycle(unsigned int NewCycleTime) { CycleTime = NewCycleTime; }

		bool Cycle();
	
	};

	class DynamicMillisTimer //repeating rate is dynamic, if more time than given has passed between 2 calls to member function Cycle(), the lost time will be made up again in further calls to Cycle()
	{
	protected:
		unsigned long LastMillis;
		unsigned int CycleTime;
	
	public:
		DynamicMillisTimer(unsigned int CycleTime = 0);

		inline void SetCycle(unsigned int NewCycleTime) { CycleTime = NewCycleTime; }

		bool Cycle();
	
	};

}

#endif