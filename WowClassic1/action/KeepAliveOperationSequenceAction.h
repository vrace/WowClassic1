#ifndef __KEEP_ALIVE_OPERATION_SEQUENCE_ACTION_H__
#define __KEEP_ALIVE_OPERATION_SEQUENCE_ACTION_H__

#include "KeepAliveOperationAction.h"
#include "KeepAliveOperationSequenceActionSteps.h"

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
