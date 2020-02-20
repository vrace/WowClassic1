#include "OperationWaitAction.h"

OperationWaitAction::OperationWaitAction(double _duration)
	: duration(_duration)
	, elapsed(0)
{
}

void OperationWaitAction::tick(double deltaSeconds)
{
	elapsed += deltaSeconds;
}

bool OperationWaitAction::isComplete()
{
	return elapsed >= duration;
}
