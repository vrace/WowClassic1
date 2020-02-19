#include "KeepAliveOperationSequenceActionStepsImpl.h"

KeepAliveOperationSequenceActionStepsImpl::~KeepAliveOperationSequenceActionStepsImpl()
{
	for (auto p : steps)
		delete p;
	steps.clear();
}

void KeepAliveOperationSequenceActionStepsImpl::add(KeepAliveOperationActionStep *step)
{
	steps.push_back(step);
}

int KeepAliveOperationSequenceActionStepsImpl::numberOfSteps()
{
	return (int)steps.size();
}

double KeepAliveOperationSequenceActionStepsImpl::expectedDurationForStepAtIndex(int index)
{
	if (index < 0 || index >= numberOfSteps())
		return 0;

	return steps[index]->expectedDuration();
}

void KeepAliveOperationSequenceActionStepsImpl::performStepAtIndex(int index)
{
	if (index < 0 || index >= numberOfSteps())
		return;

	steps[index]->perform();
}

