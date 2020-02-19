#include "KeepAliveOperationForwardAction.h"
#include "../step/KeepAliveOperationActionKeyDownStep.h"
#include "../step/KeepAliveOperationActionKeyUpStep.h"
#include "../step/KeepAliveOperationActionWaitStep.h"

#include <Windows.h>

KeepAliveOperationForwardAction::KeepAliveOperationForwardAction()
	: KeepAliveOperationSequenceAction(&steps)
{
}

KeepAliveOperationForwardActionSteps::KeepAliveOperationForwardActionSteps()
{
	steps.push_back(new KeepAliveOperationActionKeyDownStep('W'));
	steps.push_back(new KeepAliveOperationActionWaitStep((200 + rand() % 300) / 1000.0));
	steps.push_back(new KeepAliveOperationActionKeyUpStep('W'));
}

KeepAliveOperationForwardActionSteps::~KeepAliveOperationForwardActionSteps()
{
	for (auto p : steps)
		delete p;
	steps.clear();
}

int KeepAliveOperationForwardActionSteps::numberOfSteps()
{
	return (int)steps.size();
}

double KeepAliveOperationForwardActionSteps::expectedDurationForStepAtIndex(int index)
{
	// TODO: sanity check
	return steps[index]->expectedDuration();
}

void KeepAliveOperationForwardActionSteps::performStepAtIndex(int index)
{
	// TODO: sanity check
	return steps[index]->perform();
}
