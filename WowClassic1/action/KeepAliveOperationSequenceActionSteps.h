#ifndef __KEEP_ALIVE_OPERATION_SEQUENCE_ACTION_STEPS_H__
#define __KEEP_ALIVE_OPERATION_SEQUENCE_ACTION_STEPS_H__

class KeepAliveOperationSequenceActionSteps
{
public:
	virtual ~KeepAliveOperationSequenceActionSteps();
	virtual int numberOfSteps() = 0;
	virtual double expectedDurationForStepAtIndex(int index) = 0;
	virtual void performStepAtIndex(int index) = 0;
};

#endif
