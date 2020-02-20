#ifndef __OPERATION_KEY_DOWN_ACTION_H__
#define __OPERATION_KEY_DOWN_ACTION_H__

#include "OperationAction.h"

class OperationKeyDownAction : public OperationAction
{
public:
	OperationKeyDownAction(unsigned char keyCode);
	void tick(double deltaSeconds) override;
	bool isComplete() override;

private:
	unsigned char keyCode;
};

#endif
