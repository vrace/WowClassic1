#include "KeepAliveOperationActionFactory.h"
#include "../action/KeepAliveOperationIdleAction.h"
#include "../action/KeepAliveOperationJumpAction.h"

#include <stdlib.h>

static enum AvailableAction
{
	aaIdle,
	aaJump,

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

KeepAliveOperationAction* KeepAliveOperationActionFactory::create()
{
	int idx = shouldIdle ? 0 : 1 + rand() % (aaItemCount - 1);
	shouldIdle = !shouldIdle;

	switch (idx)
	{
	case aaIdle:
		return new KeepAliveOperationIdleAction(10.0 + (rand() % 1000) / 100.0);

	case aaJump:
		return new KeepAliveOperationJumpAction();

	default:
		break;
	}

	return new KeepAliveOperationIdleAction(1000);
}
