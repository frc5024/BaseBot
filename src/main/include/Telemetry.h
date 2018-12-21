//! Tools for working with telemetry data
#include <WPILib.h>

// | 1 | 2 | 3 | 4 |

namespace Telemetry{
	namespace ControlData{
		
		
		// OLD
		// A blank value struct
		struct ControlValue{
			int index;
			int value;
		}
		
		// All possible values
		
		// Robot States
		ControlValue Enabled  = {0,1}; //!< Robot enabled
		ControlValue Disabled = {0,0}; //!< Robot disabled
		
		// Robot Modes
		ControlValue Autonomous = {1,0}; //!< AUTO mode
		ControlValue Teleop     = {1,1}; //!< TELEOP mode
		ControlValue Practice   = {1,2}; //!< PRACTICE mode
		ControlValue Test       = {1,3}; //!< TEST mode
		
		// Readys
		ControlValue RIOready   = {2,1}; //!< RoboRIO is ready
		ControlValue RIOunready = {2,0}; //!< RoboRIO is not ready
		
		ControlValue PIready   = {3,1}; //!< RaspberryPI is ready
		ControlValue PIunready = {3,0}; //!< RaspberryPI is not ready
	}
	
	class TelemetryController{
		public:
			TelemetryController(); //!< Class constructor
			
			/**
			 * An interface method for manipulating controlData
			 *
			 * @param state A data struct from Telemetry::ControlData
			 */
			void SetState(ControlData::ControlValue state);
		
		private:
			int controlData[4]Q;     //!< Array of ints for storing data
			int lastControlData[4]; //!< Array to contain the last set of data sent over the network
	}
	
}

