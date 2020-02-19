#ifndef __KEEP_ALIVE_OPERATION_FORWARD_ACTION_H__
#define __KEEP_ALIVE_OPERATION_FORWARD_ACTION_H__

#include "KeepAliveOperationSequenceAction.h"

class KeepAliveOperationForwardActionSteps : public KeepAliveOperationSequenceActionSteps
{
public:
	KeepAliveOperationForwardActionSteps();

	int numberOfSteps() override;
	double expectedDurationForStepAtIndex(int index) override;
	void performStepAtIndex(int index) override;

private:
	double waitPeriod;
};

class KeepAliveOperationForwardAction : public KeepAliveOperationSequenceAction
{
public:
	KeepAliveOperationForwardAction();

private:
	KeepAliveOperationForwardActionSteps steps;
};

#endif
