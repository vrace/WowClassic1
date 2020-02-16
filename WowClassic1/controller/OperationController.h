#ifndef __OPERATION_CONTROLLER_H__
#define __OPERATION_CONTROLLER_H__

class OperationController
{
public:
	virtual ~OperationController();
	virtual void tick() = 0;
};

#endif
