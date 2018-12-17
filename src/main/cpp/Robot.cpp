#include "Robot.h"

#include <Commands/Scheduler.h>
#include <SmartDashboard/SmartDashboard.h>
#include <iostream>

#include "Utilities/Log.h"

#include "MotionProfile/CommandGroups/TestCommandGroup.h"

// Subsystems
DriveTrain *Robot::m_DriveTrain;
OI *Robot::m_OI;

void Robot::RobotInit()
{
  // Subsystems
  LOG("Initializing Subsystems...");
  this->m_DriveTrain = new DriveTrain();
  this->m_OI = new OI();

  // Init camera
  LOG("Starting CameraServer...");
  // CameraServer::GetInstance()->StartAutomaticCapture();

  // Init commands
  LOG("Creating Commands...");
  this->pDriveWithJoystick = new DriveWithJoystick();
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() { frc::Scheduler::GetInstance()->Run(); }

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString code to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons to
 * the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit()
{
  LOG("[Robot] Autonomous Initialized");

  pAutonomousCommand = new TestCommandGroup();
  pAutonomousCommand->Start();
}

void Robot::AutonomousPeriodic() 
{ 
  frc::Scheduler::GetInstance()->Run(); 
}

/**
 * 
 */
void Robot::TeleopInit()
{
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (pAutonomousCommand != nullptr) {
    pAutonomousCommand->Cancel();
    pAutonomousCommand = nullptr;
  }

  if (this->pDriveWithJoystick != nullptr) {
    this->pDriveWithJoystick->Start();
  }
}

void Robot::TeleopPeriodic() { frc::Scheduler::GetInstance()->Run(); }

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
START_ROBOT_CLASS(Robot)
#endif
