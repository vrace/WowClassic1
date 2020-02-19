#include "KeepAliveOperationActionFactory.h"
#include "../action/KeepAliveOperationIdleAction.h"
#include "../action/KeepAliveOperationSequenceAction.h"
#include "../action/KeepAliveOperationJumpAction.h"
#include "../action/KeepAliveOperationForwardAction.h"

#include <stdlib.h>

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

	case aaForward:
		return new KeepAliveOperationForwardAction();

	default:
		break;
	}

	return new KeepAliveOperationIdleAction(10);
}
