#ifndef __KEEP_ALIVE_OPERATION_ACTION_KEY_DOWN_STEP_H__
#define __KEEP_ALIVE_OPERATION_ACTION_KEY_DOWN_STEP_H__

#include "KeepAliveOperationActionStep.h"

class KeepAliveOperationActionKeyDownStep : public KeepAliveOperationActionStep
{
public:
	KeepAliveOperationActionKeyDownStep(unsigned char keyCode);
	double expectedDuration() override;
	void perform() override;

private:
	unsigned char keyCode;
};

#endif
