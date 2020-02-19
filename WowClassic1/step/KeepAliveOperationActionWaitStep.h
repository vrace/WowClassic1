#ifndef __KEEP_ALIVE_OPERATION_ACTION_WAIT_STEP_H__
#define __KEEP_ALIVE_OPERATION_ACTION_WAIT_STEP_H__

#include "KeepAliveOperationActionStep.h"

class KeepAliveOperationActionWaitStep : public KeepAliveOperationActionStep
{
public:
	KeepAliveOperationActionWaitStep(double duration);
	double expectedDuration() override;
	void perform() override;

private:
	double duration;
};

#endif
