#ifndef _MOTIONPROFILING_HG_
#define _MOTIONPROFILING_HG_

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"
#include <pathfinder.h>
#include <tuple>

class MotionProfiling : public frc::Subsystem {
 public:
  MotionProfiling();
  void InitDefaultCommand() override;

  std::tuple<Segment, Segment> GenPath(Waypoint points, int pointCount);
	void FollowPath(auto segments);
	bool isReady();

 private:
  // Trajectory
  TrajectoryCandidate candidate;
  int candidateLegnth;
  // Array of Segments (the trajectory points) to store the trajectory in
  Segment *trajectory = malloc(length * sizeof(Segment));
  
  bool isPathGenerated = false
};

#endif // _MOTIONPROFILING_HG_