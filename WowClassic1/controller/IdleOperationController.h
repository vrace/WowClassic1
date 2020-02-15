#ifndef __IDLE_OPERATION_CONTROLLER_H__
#define __IDLE_OPERATION_CONTROLLER_H__

#include "OperationController.h"

class IdleOperationController : public OperationController
{
public:
	void tick() override;
	bool isComplete() override;
};

#endif
