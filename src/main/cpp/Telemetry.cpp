#include "Telemetry.h"
#include <iostream>

TelemetryController(){
	this->controlData = {0,0,0,0};
	// this->lastControlData not set here to stop lock on first publish
	
	std::cout << "A telemetry controller has been initalized" << std::endl;
}

void TelemetryController::SetState(ControlData::ControlValue state){
	this->controlData[state.index] = state.value;
}

