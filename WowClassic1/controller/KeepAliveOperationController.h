#ifndef __KEEP_ALIVE_OPERATION_CONTROLLER_H__
#define __KEEP_ALIVE_OPERATION_CONTROLLER_H__

#include "OperationController.h"
#include "../action/KeepAliveOperationAction.h"
#include "../factory/KeepAliveOperationActionFactory.h"
#include <memory>

class KeepAliveOperationController : public OperationController
{
public:
	void tick(double deltaSeconds) override;
	void enter() override;

private:
	std::unique_ptr<KeepAliveOperationAction> currentAction;
	KeepAliveOperationActionFactory actionFactory;
};

#endif
