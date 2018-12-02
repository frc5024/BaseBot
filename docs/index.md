# Welcome to BaseBot

BaseBot is a complete rewrite of [BarebonesFRC](https://github.com/ewpratten/barebonesfrc) with 2 goals. Do it right, and do it fast. The entire codebase is written in pure c/c++ and some components are being optimized further using ARMv7-a assembly.

## Project Layout
This project is split up into two basic sections. They are as follows:

**Commands**

 - These include autonomus code
 - Modular layer between the DriverStation and the hardware
 - Allow for drivers to interface with the robot


**Subsystems**

 - These are the layer directly above WPILib.
 - Interface with hardware
 - Get sensor data
 - Move motors
 - Can be called by multiple commands