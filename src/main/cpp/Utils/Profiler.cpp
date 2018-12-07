#include <Utils/Profiler.h>

Profiler::Profiler(std::string id){
	// Set the id for this profiler
	this->id = id;
	
	// Get the current time
	this->lastTime = std::time(nullptr);
	
	// Get the profiling data table
	this->table = NetworkTable::GetTable("Profiler");
}

void Profiler::Tick(){
	// Get the current time
	this->currentTime = std::time(nullptr);
	
	// Compare last time to current time
	this->diff = std::difftime(this->currentTime, this->lastTime);
	
	// Set last time to current time
	this->lastTime = this->currentTime;
}

void Profiler::Publish(){
	
}
