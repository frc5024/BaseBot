//! Main robot class that is called by wpilib
#ifndef _ROBOT_HG_
#define _ROBOT_HG_

#include <Commands/Command.h>
#include <SmartDashboard/SendableChooser.h>
#include <TimedRobot.h>

#include "Commands/DriveWithJoystick.h"
#include "OI.h"
#include "Subsystems/DriveTrain.h"


class Robot : public frc::TimedRobot {
 public:
	// Subsystems
  static DriveTrain *m_DriveTrain; //!< Pointer for the DriveTrain
  static OI *m_oi;                 //!< Pointer for the Operator Interface (OI)

	// Commands
  DriveWithJoystick* pDriveWithJoystick; //!< Pointer for the DriveWithJoystick command

	// Robot methods
  void RobotInit() override;          //!< Runs once on robot boot
  void RobotPeriodic() override;      //!< Runs in a loop while the robot is turned on in any mode
  void DisabledInit() override;       //!< Runs once every time the robot is disabled
  void DisabledPeriodic() override;   //!< Runs in a loop while the robot is disabled
  void AutonomousInit() override;     //!< Runs once at the start of auto. Usually while the announcer starts counting down from 3
  void AutonomousPeriodic() override; //!< Runs in a loop during auto
  void TeleopInit() override;         //!< Runs once at the start of teleop when the bell sounds
  void TeleopPeriodic() override;     //!< Runs in a loop during teleop
  void TestPeriodic() override;       //!< Runs in a loop during test mode
  
  // Period control
  /**
   * Used to set the amount of time between each cycle of the periodic functions.
   * WARNING: Anything below 0.01 will cause the motor controllers to stop working correctly in some cases
   *
   * @param seconds Time gap between cycles in seconds
   */
  void SetCycleTime(double seconds);
  
  /**
   * Get the current cycle time
   *
   * @return Current time gap between cycles in seconds
   */
  double GetCycleTime();

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  // frc::Command* m_autonomousCommand = nullptr;
  // DriveWithJoystick m_defaultAuto;
  // MyAutoCommand m_myAuto;
  frc::SendableChooser<frc::Command*> m_chooser;
  
  double cycleTime = 0.02;
};

#endif //_ROBOT_HG_