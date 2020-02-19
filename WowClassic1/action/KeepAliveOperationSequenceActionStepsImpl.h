#ifndef __KEEP_ALIVE_OPERATION_SEQUENCE_ACTION_STEPS_IMPL_H__
#define __KEEP_ALIVE_OPERATION_SEQUENCE_ACTION_STEPS_IMPL_H__

#include "KeepAliveOperationSequenceActionSteps.h"
#include "../step/KeepAliveOperationActionStep.h"

#include <vector>

class KeepAliveOperationSequenceActionStepsImpl : public KeepAliveOperationSequenceActionSteps
{
public:
	~KeepAliveOperationSequenceActionStepsImpl();

	void add(KeepAliveOperationActionStep *step);
	int numberOfSteps() override;
	double expectedDurationForStepAtIndex(int index) override;
	void performStepAtIndex(int index) override;

private:
	std::vector<KeepAliveOperationActionStep*> steps;
};

#endif
