#include "KeepAliveOperationIdleAction.h"

KeepAliveOperationIdleAction::KeepAliveOperationIdleAction(int _idleTicks)
	: idleTicks(_idleTicks)
	, elapsed(0)
{
}

void KeepAliveOperationIdleAction::tick()
{
	elapsed++;
}

bool KeepAliveOperationIdleAction::isComplete()
{
	return elapsed >= idleTicks;
}
