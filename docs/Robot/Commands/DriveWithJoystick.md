---
title: DriveWithJoystick
---

# Overview
DriveWithJoystick is a command that takes in controller data from the DriverStation or other dsconn packet sources and calls DriveTrain with the output calculated by this code.

## Input
Movement

 - Driver Jeft-Joy X axis
 - Driver Jeft-Joy Y axis

Actions

 - Driver A button
 - Driver Right bumper

## Slow Mode
Slow mode is activated by holding the right bumper on the driver's controller. This will decrease the speed of the robot to 50-80% of it's normal speed.

## Reverse Heading
Pressing the X button will multiply the `speed` value by -1. This makes the robot drive in the oposite direciton while still having intuitive steering.

## Speed and Rotation Calculation Overview
This is a rough, pseudocode outline of how the speed and rotation are calculated.
```
speed    = joyDrive.getY() * -1
rotation = joyDrive.getX()

speedMultiplier     = joyDrive.getRightBumper()
direcitonMultiplier = joyDrive.getAButtonReleased()

speed    = (speed    * speedMultiplier * directionMultiplier)
rotation = (rotation * speedMultiplier)
```

After this, the speed and roataion are passed into the `ArcadeDrive` method of `DriveTrain`
