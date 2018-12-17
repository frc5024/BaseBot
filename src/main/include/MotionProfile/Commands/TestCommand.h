#ifndef _TESTCOMMAND_HG_
#define _TESTCOMMAND_HG_

#include <Timer.h>
#include <WPILib.h>
#include <Commands/Command.h>
#include "MotionProfile/Profiles/TestProfile.h"

/**
 *
 */
class TestCommand : public frc::Command
{
public:
	TestCommand();
	~TestCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	TestProfile* pMotionProfiler;
	Timer* pTimer;
};

#endif
