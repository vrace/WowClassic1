#include "KeepAliveOperationActionFactory.h"
#include "../action/OperationKeyPressAction.h"
#include "../action/OperationWaitAction.h"

#include <Windows.h>

static enum AvailableAction
{
	aaIdle,
	aaJump,
	aaForward,

	aaItemCount,
};

KeepAliveOperationActionFactory::KeepAliveOperationActionFactory()
	: shouldIdle(true)
{
}

void KeepAliveOperationActionFactory::enter()
{
	shouldIdle = true;
}

OperationAction* KeepAliveOperationActionFactory::create()
{
	int idx = shouldIdle ? 0 : 1 + rand() % (aaItemCount - 1);
	shouldIdle = !shouldIdle;

	switch (idx)
	{
	case aaIdle:
		return new OperationWaitAction(10.0 + (rand() % 1000) / 100.0);

	case aaJump:
		return new OperationKeyPressAction(VK_SPACE);

	case aaForward:
		return new OperationKeyPressAction('W');

	default:
		break;
	}

	return new OperationWaitAction(10);
}
