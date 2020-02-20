#ifndef __OPERATION_SEQUENCE_ACTION_H__
#define __OPERATION_SEQUENCE_ACTION_H__

#include "OperationAction.h"
#include <vector>

class OperationSequenceAction : public OperationAction
{
public:
	OperationSequenceAction();
	OperationSequenceAction(const std::vector<OperationAction*> &steps);
	~OperationSequenceAction();

	void addAction(OperationAction *action);

	void tick(double deltaSeconds) override;
	bool isComplete() override;

private:
	int current;
	std::vector<OperationAction*> steps;
};

#endif
