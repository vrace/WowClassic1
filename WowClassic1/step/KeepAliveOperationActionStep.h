#ifndef __KEEP_ALIVE_OPERATION_ACTION_STEP_H__
#define __KEEP_ALIVE_OPERATION_ACTION_STEP_H__

class KeepAliveOperationActionStep
{
public:
	virtual ~KeepAliveOperationActionStep();
	virtual double expectedDuration() = 0;
	virtual void perform() = 0;
};

#endif
