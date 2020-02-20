#ifndef __OPERATION_WAIT_ACTION_H__
#define __OPERATION_WAIT_ACTION_H__

#include "OperationAction.h"

class OperationWaitAction : public OperationAction
{
public:
	OperationWaitAction(double duration);
	void tick(double deltaSeconds) override;
	bool isComplete() override;

private:
	double elapsed;
	double duration;
};

#endif
