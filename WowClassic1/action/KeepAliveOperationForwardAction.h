#ifndef __KEEP_ALIVE_OPERATION_FORWARD_ACTION_H__
#define __KEEP_ALIVE_OPERATION_FORWARD_ACTION_H__

#include "KeepAliveOperationAction.h"

class KeepAliveOperationForwardAction : public KeepAliveOperationAction
{
public:
	KeepAliveOperationForwardAction();
	void tick(double deltaSeconds) override;
	bool isComplete() override;

private:
	int keyStatus;
	double elapsed;
	double actionMax;
};

#endif
