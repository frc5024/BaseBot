//! Tools for working with telemetry data
#include <WPILib.h>

[0,0,0,0]

namespace Telemetry{
	namespace ControlData{
		// A blank value struct
		struct ControlValue{
			int index;
			int value;
		}
		
		// All possible values
		
		// Robot States
		ControlValue Enabled  = {0,1};
		ControlValue Disabled = {0,0};
		
		// Robot Modes
		ControlValue Autonomous = {1,0};
		ControlValue Teleop     = {1,1};
		ControlValue Practice   = {1,2};
		ControlValue Test       = {1,3};
		
		// Readys
		ControlValue RIOready   = {2,1};
		ControlValue RIOunready = {2,0};
		
		ControlValue PIready   = {3,1};
		ControlValue PIunready = {3,0};
	}
	
	class TelemetryController{
		public:
			TelemetryController();
			
			void SetState(ControlData::ControlValue state);
		
		private:
			double controlData     = 0.00;
			double lastControlData = 0.00;
	}
	
}

