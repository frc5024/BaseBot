---
title: DriveTrain
---

# Overview
The DriveTrain is the subsystem that interfaces with the motor controllers (Talon SRX) to make the robot move.

## Setup
DriveTrain sets up the motor controllers in the following ways:
 - Assign each controller to a motor
 - Slave the controllers to eachother on each side of the robot (to act like one controller per side)
 - Reverse motors that where incorrectly wired
 - Disable saftey mode

## ArcadeDrive
This function takes in a forward speed and a rotation, then passes them to WPILib's ArcadeDrive function.

## TankDrive
This function takes in a left and right speed, then passes them to WPILib's TankDrive function.