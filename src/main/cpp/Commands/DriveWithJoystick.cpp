#include "Commands/DriveWithJoystick.h"

#include "Robot.h"

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

  //set Speed and Rotation
  this->speed    = 0.0;
  this->rotation = 0.0;
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {
  // Deal with reversing and slow mode
	this->directionMultiplier *= (this->pJoyDrive->GetXButtonReleased())? -1 : 1;
  this->speedMultiplier      = (this->pJoyDrive->GetBumper(XboxController::kRightHand)) ? SLOWMODE_MULTIPLIER : 1;
  
  // Check if QuickTurn is to be enabled
  this->isQuickTurn = this->pJoyDrive->GetBumper(XboxController::kLeftHand);

  // Get movement data form controller
  this->force = pJoyDrive->GetY(XboxController::kLeftHand) * -1;
	this->curve = pJoyDrive->GetX(XboxController::kLeftHand);

	// Calculate Force and Curve with multipliers
  this->force = (this->force * this->speedMultiplier * this->directionMultiplier);
  this->curve = (this->curve * this->speedMultiplier);

  Robot::m_DriveTrain->RaiderDrive(this->force, this->curve, this->isQuickTurn);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveWithJoystick::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted() {}
