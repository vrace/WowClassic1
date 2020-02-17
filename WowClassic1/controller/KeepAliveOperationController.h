#ifndef __KEEP_ALIVE_OPERATION_CONTROLLER_H__
#define __KEEP_ALIVE_OPERATION_CONTROLLER_H__

#include "OperationController.h"
#include "../action/KeepAliveOperationJumpAction.h"
#include <memory>

class KeepAliveOperationController : public OperationController
{
public:
	void tick() override;
	void enter() override;

private:
	std::unique_ptr<KeepAliveOperationJumpAction> currentAction;
};

#endif
