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
			Teleop   = 10,
			Practice = 20,
			Test     = 30
		} RobotMode;
		
		typedef enum RIO{ //!< Current state of the RoboRIO
			Unready = 0,
			Ready   = 100,
			Fault   = 200
		} RIO;
		
		typedef enum RPI{ //!< Current state of the RaspberryPI
			Unready = 0,
			Ready   = 1000,
			Fault   = 2000
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
			int controlData[4];     //!< Array of ints for storing data
			int lastControlData[4]; //!< Array to contain the last set of data sent over the network
			
			double packagedData = 0.00; //!< Double for storing the encoded data
			
			// Byte map
			// |   1   |   1  |  1  |  1  |    0   |    0   |    0   |    0   |
			// | state | mode | rio | rpi | unused | unused | unused | unused |
	}
	
}

