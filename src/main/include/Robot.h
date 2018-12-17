#ifndef _ROBOT_HG_
#define _ROBOT_HG_

#include <Commands/Command.h>
#include <SmartDashboard/SendableChooser.h>
#include <TimedRobot.h>

#include "OI.h"
#include "Subsystems/DriveTrain.h"
#include "Commands/DriveWithJoystick.h"

/**
 * 
 */
class Robot : public frc::TimedRobot
{
  public:
    // Subsystems
    static DriveTrain *m_DriveTrain;
    static OI *m_OI;

    // Commands
    DriveWithJoystick *pDriveWithJoystick;

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
    frc::Command* pAutonomousCommand = nullptr;
};

#endif //_ROBOT_HG_