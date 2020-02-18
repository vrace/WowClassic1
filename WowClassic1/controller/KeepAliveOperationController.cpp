#include "KeepAliveOperationController.h"

#include <Windows.h>

void KeepAliveOperationController::enter()
{
	actionFactory.enter();
	currentAction.reset(actionFactory.create());
}

void KeepAliveOperationController::tick(double deltaSeconds)
{
	if (currentAction)
		currentAction->tick(deltaSeconds);

	if (!currentAction || currentAction->isComplete())
		currentAction.reset(actionFactory.create());
}
