#ifndef __KEEP_ALIVE_OPERATION_ACTION_KEY_UP_STEP_H__
#define __KEEP_ALIVE_OPERATION_ACTION_KEY_UP_STEP_H__

#include "KeepAliveOperationActionStep.h"

class KeepAliveOperationActionKeyUpStep : public KeepAliveOperationActionStep
{
public:
	KeepAliveOperationActionKeyUpStep(unsigned char keyCode);
	double expectedDuration() override;
	void perform() override;

private:
	unsigned char keyCode;
};

#endif
