#include "Subsystems/MotionProfiling.h"

MotionProfiling::MotionProfiling() : frc::Subsystem("MotionProfiling") {  }

void MotionProfiling::InitDefaultCommand() {
  // SetDefaultCommand(new DriveWithJoystick());
}

std::tuple<Segment, Segment> MotionProfiling::GenPath(Waypoint points, int pointCount) {
	// Generate path points using data about the robot and the waypoints
	pathfinder_prepare(points, pointCount, FIT_HERMITE_CUBIC, PATHFINDER_SAMPLES_HIGH, MP_TIME_STEP, MP_MAX_VELOCITY, MP_MAX_ACCELERATION, MP_MAX_JERK, &this->candidate);
	
	// Get the legnth of the generated output
	this->candidateLegnth = this->candidate.length;
	
	// Generate the path
	pathfinder_generate(&this->candidate, this->trajectory);
	
	// Create segments for each motor group
	Segment leftTrajectory [this->candidateLegnth];
	Segment rightTrajectory[this->candidateLegnth];
	
	// Modify for tank drive
	pathfinder_modify_tank(this->trajectory, this->candidateLegnth, leftTrajectory, rightTrajectory, WHEELBASE_WIDTH);
	
	this->isPathGenerated = true;
	return std::make_tuple(leftTrajectory, rightTrajectory);
}

void MotionProfiling::FollowPath(auto segments) {
	EncoderFollower leftFollower = malloc(sizeof(EncoderFollower));
	leftFollower.last_error = 0; leftFollower.segment = 0; leftFollower.finished = 0;     // Just in case!
	
	EncoderFollower rightFollower = malloc(sizeof(EncoderFollower));
	rightFollower.last_error = 0; rightFollower.segment = 0; rightFollower.finished = 0;     // Just in case!
	
	EncoderConfig leftConfig = { encoder_position, 1000, wheel_circumference,      // Position, Ticks per Rev, Wheel Circumference
                         1.0, 0.0, 0.0, 1.0 / max_velocity, 0.0};          // Kp, Ki, Kd and Kv, Ka
	
	EncoderConfig rightConfig = { encoder_position, 1000, wheel_circumference,      // Position, Ticks per Rev, Wheel Circumference
                         1.0, 0.0, 0.0, 1.0 / max_velocity, 0.0};          // Kp, Ki, Kd and Kv, Ka
	
	// Arg 1: The EncoderConfig
	// Arg 2: The EncoderFollower for this side
	// Arg 3: The Trajectory generated from `pathfinder_modify_tank`
	// Arg 4: The Length of the Trajectory (length used in Segment seg[length];)
	// Arg 5: The current value of your encoder
	double l = pathfinder_follow_encoder(leftConfig,  &leftFollower,  std::get<0>(segments), trajectory_length, l_encoder_value);
	double r = pathfinder_follow_encoder(rightConfig, &rightFollower, std::get<1>(segments), trajectory_length, r_encoder_value);
	return;
}

bool isReady(){
	return this->isPathGenerated;
}