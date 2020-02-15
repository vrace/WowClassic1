#ifndef __OPERATION_CONTROLLER_FACTORY_H__
#define __OPERATION_CONTROLLER_FACTORY_H__

#include "../controller/OperationController.h"

class OperationControllerFactory
{
public:
	virtual ~OperationControllerFactory();
	virtual OperationController* create() = 0;
};

#endif
