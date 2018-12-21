//! Tools for working with telemetry data
#include <WPILib.h>

namespace Telemetry{
	namespace ControlData{
		typedef enum RobotState{ //!< Current state of the robot
			Disabled = 0,
			Enabled  = 1
		} RobotState;
		
		typedef enum RobotMode{ //!< Current mode of the robot
			Auto     = 0,
			Teleop   = 1,
			Practice = 2,
			Test     = 3
		} RobotMode;
		
		typedef enum RIO{ //!< Current state of the RoboRIO
			Unready = 0,
			Ready   = 1,
			Fault   = 2
		} RIO;
		
		typedef enum RPI{ //!< Current state of the RaspberryPI
			Unready = 0,
			Ready   = 1,
			Fault   = 2
		} RPI;
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

