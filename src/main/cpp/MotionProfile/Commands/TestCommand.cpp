#include "MotionProfile/Commands/TestCommand.h"
#include "Utilities/Log.h"

#include "Robot.h"

/**
 *
 */
TestCommand::TestCommand()
{
	LOG("[TestCommand] Constructed");

	Requires(Robot::m_DriveTrain);
	this->pMotionProfiler = new TestProfile(*Robot::m_DriveTrain->GetLeftFrontMotor(), *Robot::m_DriveTrain->GetRightFrontMotor());
	this->pTimer = new Timer();

	return;
}

/**
 *
 */
TestCommand::~TestCommand()
{
	delete this->pTimer;
	delete this->pMotionProfiler;

	return;
}

/**
 *
 */
void TestCommand::Initialize()
{
	LOG("[TestCommand] Initializing" );

	this->pTimer->Reset();
	this->pTimer->Start();

	Robot::m_DriveTrain->InitMotionProfilingMode();

	return;
}

/**
 *
 */
void TestCommand::Execute()
{
	this->pMotionProfiler->control();
	this->pMotionProfiler->PeriodicTask();

	SetValueMotionProfile setOutput = this->pMotionProfiler->getSetValue();

	LOG("[TestCommand] Set Output: " << setOutput);

	Robot::m_DriveTrain->GetLeftFrontMotor()->Set(ControlMode::MotionProfile, setOutput);
	Robot::m_DriveTrain->GetRightFrontMotor()->Set(ControlMode::MotionProfile, setOutput);

	this->pMotionProfiler->start();

	return;
}

/**
 *
 */
bool TestCommand::IsFinished()
{
	if (this->pMotionProfiler->isFinished())
	{
		LOG("[TestCommand] MP Finished");

		return true;
	}

	return false;
}

/**
 *
 */
void TestCommand::End()
{
	LOG("[TestCommand] Ending" );

	this->pMotionProfiler->reset();
	Robot::m_DriveTrain->ResetDrive();

	return;
}

/**
 *
 */
void TestCommand::Interrupted()
{
	LOG("[TestCommand] Interrupted" );

	this->pMotionProfiler->reset();
	Robot::m_DriveTrain->ResetDrive();

	return;
}
