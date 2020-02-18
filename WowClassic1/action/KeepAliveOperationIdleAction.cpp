#include "KeepAliveOperationIdleAction.h"

KeepAliveOperationIdleAction::KeepAliveOperationIdleAction(double _idleMax)
	: idleMax(_idleMax)
	, elapsed(0)
{
}

void KeepAliveOperationIdleAction::tick(double deltaSeconds)
{
	elapsed += deltaSeconds;
}

bool KeepAliveOperationIdleAction::isComplete()
{
	return elapsed >= idleMax;
}
