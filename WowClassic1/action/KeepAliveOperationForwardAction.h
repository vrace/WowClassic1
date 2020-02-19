#ifndef __KEEP_ALIVE_OPERATION_FORWARD_ACTION_H__
#define __KEEP_ALIVE_OPERATION_FORWARD_ACTION_H__

#include "KeepAliveOperationSequenceAction.h"
#include "../step/KeepAliveOperationActionStep.h"
#include <vector>

class KeepAliveOperationForwardActionSteps : public KeepAliveOperationSequenceActionSteps
{
public:
	KeepAliveOperationForwardActionSteps();
	~KeepAliveOperationForwardActionSteps();

	int numberOfSteps() override;
	double expectedDurationForStepAtIndex(int index) override;
	void performStepAtIndex(int index) override;

private:
	std::vector<KeepAliveOperationActionStep*> steps;
};

class KeepAliveOperationForwardAction : public KeepAliveOperationSequenceAction
{
public:
	KeepAliveOperationForwardAction();

private:
	KeepAliveOperationForwardActionSteps steps;
};

#endif
