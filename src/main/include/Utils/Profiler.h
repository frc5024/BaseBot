#ifndef _PROFILER_HG_
#define _PROFILER_HG_

#include <ctime>
#include <WPILib.h>
#include <string>

class Profiler{
	public:
		Profiler(std::string id); //!< Class constructor
		
		void Tick(); //!< Run every time the profiler should tick
	
	private:
		void Publish();
		
		std::string id;
		std::time_t lastTime;
		std::time_t currentTime;
		double diff;
		
		std::shared_ptr<NetworkTable> table;
}

#endif //_PROFILER_HG_