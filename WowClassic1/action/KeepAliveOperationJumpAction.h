#ifndef __KEEP_ALIVE_OPERATION_JUMP_ACTION_H__
#define __KEEP_ALIVE_OPERATION_JUMP_ACTION_H__

#include "KeepAliveOperationAction.h"

class KeepAliveOperationJumpAction : public KeepAliveOperationAction
{
public:
	KeepAliveOperationJumpAction();
	void tick() override;
	bool isComplete() override;

private:
	int elapsed;
	int totalTicks;
};

#endif
