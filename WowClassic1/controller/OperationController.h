#ifndef __OPERATION_CONTROLLER_H__
#define __OPERATION_CONTROLLER_H__

class OperationController
{
public:
	virtual ~OperationController();
	virtual void tick(double deltaSeconds) = 0;
	virtual void enter() = 0;
};

#endif
