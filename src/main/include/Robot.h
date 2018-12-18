#ifndef _ROBOT_HG_
#define _ROBOT_HG_

#include <Commands/Command.h>
#include <SmartDashboard/SendableChooser.h>
#include <TimedRobot.h>

#include "Commands/DriveWithJoystick.h"
#include "Commands/MoveElevator.h"
#include "Commands/MoveIntake.h"
#include "OI.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/Intake.h"

class Robot : public frc::TimedRobot {
 public:
	// Subsystems
  static DriveTrain *m_DriveTrain;
  static OI *m_oi;
  static Elevator *m_Elevator;
  static Intake *m_Intake;

	// Commands
  DriveWithJoystick* pDriveWithJoystick;
  MoveElevator* pMoveElevator;
  MoveIntake* pMoveIntake;


	// Robot methods
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  // frc::Command* m_autonomousCommand = nullptr;
  // DriveWithJoystick m_defaultAuto;
  // MyAutoCommand m_myAuto;
  frc::SendableChooser<frc::Command*> m_chooser;
};

#endif //_ROBOT_HG_