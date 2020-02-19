#ifndef __KEEP_ALIVE_OPERATION_SEQUENCE_ACTION_H__
#define __KEEP_ALIVE_OPERATION_SEQUENCE_ACTION_H__

#include "KeepAliveOperationAction.h"

class KeepAliveOperationSequenceActionSteps
{
public:
	virtual int numberOfSteps() = 0;
	virtual double expectedDurationForStepAtIndex(int index) = 0;
	virtual void performStepAtIndex(int index) = 0;
};

class KeepAliveOperationSequenceAction : public KeepAliveOperationAction
{
public:
	KeepAliveOperationSequenceAction(KeepAliveOperationSequenceActionSteps *steps);
	void tick(double deltaSeconds) override;
	bool isComplete() override;

private:
	KeepAliveOperationSequenceActionSteps *steps;
	int currentStep;
	double elapsed;
};

#endif
