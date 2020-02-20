#ifndef __OPERATION_KEY_UP_ACTION_H__
#define __OPERATION_KEY_UP_ACTION_H__

#include "OperationAction.h"

class OperationKeyUpAction : public OperationAction
{
public:
	OperationKeyUpAction(unsigned char keyCode);
	void tick(double deltaSeconds) override;
	bool isComplete() override;

private:
	unsigned char keyCode;
};

#endif
