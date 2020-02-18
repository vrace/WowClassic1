#ifndef __KEEP_ALIVE_OPERATION_IDLE_ACTION_H__
#define __KEEP_ALIVE_OPERATION_IDLE_ACTION_H__

#include "KeepAliveOperationAction.h"

class KeepAliveOperationIdleAction : public   KeepAliveOperationAction
{
public:
	KeepAliveOperationIdleAction(double idleMax);
	void tick(double deltaSeconds) override;
	bool isComplete() override;

private:
	double elapsed;
	double idleMax;
};

#endif
