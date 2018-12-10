#include "Commands/DriveWithJoystick.h"
#include "Robot.h"
 bool useVision = true;

DriveWithJoystick::DriveWithJoystick() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::m_DriveTrain);
  this->pJoyDrive = Robot::m_oi->GetJoystickDrive();
}

// Called just before this Command runs the first time
// aka: every time teleop is enabled
void DriveWithJoystick::Initialize() {
  // Set speed and direction multipliers
  this->directionMultiplier = 1;
  this->speedMultiplier     = 1;
  table = NetworkTable::GetTable("SmartDashboard");

  //set Speed and Rotation
  this->speed    = 0.0;
  this->rotation = 0.0;
  
  //driverMenu selection
  //To use driverMenu, hold a selection button while enabling teleop
  
  // Make sure that driveMode is reset each time the bot is enabled
  // This must be in the Initalize() function, not in the header file
  this->driveMode = 0;

  // If X held during teleop enable, use triggerdrive
  if(this->pJoyDrive->GetYButton()){
  	this->driveMode = 1;
  }
}

bool inline DriveWithJoystick::getTriggers(){
  // Speed = Right trigger - left trigger
  this->speed = (this->pJoyDrive->GetTriggerAxis(XboxController::kRightHand) - this->pJoyDrive->GetTriggerAxis(XboxController::kLeftHand));
  
  // needed for use in an and statement
  return true;
}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {
 
  // Deal with reversing and slow mode
	this->directionMultiplier = (this->pJoyDrive->GetXButtonReleased())? -1 : 1;
  this->speedMultiplier     = (this->pJoyDrive->GetBumper(XboxController::kRightHand)) ? 0.5 : 1;

  // Get movement data form controller
  this->speed    = this->pJoyDrive->GetY(XboxController::kLeftHand) * -1;
	this->rotation = this->pJoyDrive->GetX(XboxController::kLeftHand);

  // If trigger drive mode was enabled during teleop-init, override speed with trigger data
  // This will only ever be called if a select few people are driving the bot.
  // It should be as insignifigant as possible when the bot is in normal operation (3 instructions)
  this->driveMode == 1 && this->getTriggers();
	
	// Multiply each value with it's multiplier(s)
  this->speed    *= (this->speedMultiplier * this->directionMultiplier);
  this->rotation *= (this->speedMultiplier * DRIVEWITHJOYSTICK_ROTATION_LIMITER);

    if(useVision) {
	      this->speed = table->GetNumber("DistanceToCube",0.0) / 100;
	      this->rotation = table->GetNumber("AngleToCube",0.0) / 100;
  }	

  Robot::m_DriveTrain->ArcadeDrive(this->speed, this->rotation);
  
  // Reset the speed and rotation
  // while this does have some negitive side effects while driving,
  // It is for saftey. (and so we don't have a run-away bot slam into a wall again)
  this->speed    = 0.00;
  this->rotation = 0.00;
}


bool DriveWithJoystick::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveWithJoystick::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted() {}
