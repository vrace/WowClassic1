#include "KeepAliveOperationSequenceAction.h"

KeepAliveOperationSequenceAction::KeepAliveOperationSequenceAction(KeepAliveOperationSequenceActionSteps *_steps)
	: steps(_steps)
	, currentStep(0)
	, elapsed(0)
{
}

void KeepAliveOperationSequenceAction::tick(double deltaSeconds)
{
	elapsed += deltaSeconds;

	if (steps && currentStep < steps->numberOfSteps())
	{
		double expected = steps->expectedDurationForStepAtIndex(currentStep);
		if (elapsed >= expected) {
			steps->performStepAtIndex(currentStep);
			currentStep++;
			elapsed -= expected;
		}
	}
}

bool KeepAliveOperationSequenceAction::isComplete()
{
	return !steps || currentStep >= steps->numberOfSteps();
}
