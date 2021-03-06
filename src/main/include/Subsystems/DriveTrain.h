//! A subsystem that interfaces with the drivebase on the robot
#ifndef _DRIVETRAIN_HG_
#define _DRIVETRAIN_HG_

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <ctre/Phoenix.h>
#include <Drive/DifferentialDrive.h>
#include "RobotMap.h"
#include <Commands/DriveWithJoystick.h>

class DriveTrain : public frc::Subsystem {
 public:
  DriveTrain(); //!< Class constructor
  void InitDefaultCommand() override; //!< Initalizes the default command for this subsystem (DriveWithJoystick)
	
	/**
	 * Pass data to wpilib's ArcadeDrive
	 *
	 * @param xSpeed Forward speed (form -1 to 1)
	 * @param zRotation Rotation (from -1 to 1)
	 */
  void ArcadeDrive(double xSpeed, double zRotation);
  
  /**
   * Passes data to wpilib's TankDrive
   *
   * @param leftSpeed left motor speed
   * @param rightSpeed right motor speed
   */
	void TankDrive(double leftSpeed, double rightSpeed);

 private:
  can::WPI_TalonSRX* pLeftFrontMotor; //!< Pointer for left front motor
	can::WPI_TalonSRX* pLeftRearMotor;  //!< Pointer for left rear motor
	can::WPI_TalonSRX* pRightFrontMotor;//!< Pointer for right front motor
	can::WPI_TalonSRX* pRightRearMotor; //!< Pointer for right rear motor

	frc::DifferentialDrive* pRobotDrive; //!< Pointer for a differential drivebase made up of 2 motor pairs
};

#endif // _DRIVETRAIN_HG_