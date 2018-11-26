#include "Commands/DriveWithJoystick.h"

#include "Robot.h"
bool vision = true;

DriveWithJoystick::DriveWithJoystick() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::m_DriveTrain);
  this->pJoyDrive = Robot::m_oi->GetJoystickDrive();
}

// Called just before this Command runs the first time
void DriveWithJoystick::Initialize() {
  // Set speed and direction multipliers
  this->directionMultiplier = 1;
  this->speedMultiplier     = 1;

 //set up table for vision
  table = NetworkTable::GetTable("SmartDashboard");
  //set Speed and Rotation
  this->speed    = 0.0;
  this->rotation = 0.0;
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {
  // Deal with reversing and slow mode
	this->directionMultiplier *= (this->pJoyDrive->GetXButtonReleased())? -1 : 1;
  this->speedMultiplier = (this->pJoyDrive->GetBumper(XboxController::kRightHand)) ? 0.5 : 1;

  // Get movement data form controller
  this->speed    = pJoyDrive->GetY(XboxController::kLeftHand) * -1;
	this->rotation = pJoyDrive->GetX(XboxController::kLeftHand);

  this->speed    = (this->speed * this->speedMultiplier * this->directionMultiplier);
  this->rotation = (this->rotation * this->directionMultiplier);
	
  //get speed and angle from networktables
  if(vision) {
	  this->speed = table->GetNumber("DistanceToCube",0.00) / 100);
	  this->rotation = table->GetNumber("AngleToCube,0.00) / 100);
  }	

  Robot::m_DriveTrain->ArcadeDrive(this->speed, this->rotation);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveWithJoystick::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted() {}
