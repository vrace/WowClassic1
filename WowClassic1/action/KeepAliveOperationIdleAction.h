#ifndef __KEEP_ALIVE_OPERATION_IDLE_ACTION_H__
#define __KEEP_ALIVE_OPERATION_IDLE_ACTION_H__

#include "KeepAliveOperationAction.h"

class KeepAliveOperationIdleAction : public KeepAliveOperationAction
{
public:
	KeepAliveOperationIdleAction(int idleTicks = 100);
	void tick() override;
	bool isComplete() override;

private:
	int elapsed;
	int idleTicks;
};

#endif
