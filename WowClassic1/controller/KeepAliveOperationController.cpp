#include "KeepAliveOperationController.h"

#include <Windows.h>

void KeepAliveOperationController::enter()
{
	currentAction.reset(new KeepAliveOperationJumpAction());
}

void KeepAliveOperationController::tick()
{
	if (currentAction)
		currentAction->tick();
}
