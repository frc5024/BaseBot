#include "MotionProfile/CommandGroups/TestCommandGroup.h"
#include "Utilities/Log.h"
#include "MotionProfile/Commands/TestCommand.h"

/**
 *
 */
TestCommandGroup::TestCommandGroup()
{
    LOG("[TestCommandGroup] Constructed");

    AddSequential(new TestCommand());
}