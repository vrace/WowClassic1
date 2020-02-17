#ifndef __KEEP_ALIVE_OPERATION_CONTROLLER_H__
#define __KEEP_ALIVE_OPERATION_CONTROLLER_H__

#include "OperationController.h"

class KeepAliveOperationController : public OperationController
{
public:
	void tick() override;
	void enter() override;
};

#endif
