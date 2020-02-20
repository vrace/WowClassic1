#include "OperationSequenceAction.h"

OperationSequenceAction::OperationSequenceAction()
	: current(0)
{
}

OperationSequenceAction::OperationSequenceAction(const std::vector<OperationAction*> &_steps)
	: steps(_steps)
	, current(0)
{
}

OperationSequenceAction::~OperationSequenceAction()
{
	for (auto p : steps)
		delete p;
	steps.clear();
}

void OperationSequenceAction::addAction(OperationAction *action)
{
	steps.push_back(action);
}

void OperationSequenceAction::tick(double deltaSeconds)
{
	if (current < (int)steps.size())
	{
		auto *p = steps[current];
		p->tick(deltaSeconds);
		if (p->isComplete())
			current++;
	}
}

bool OperationSequenceAction::isComplete()
{
	return current >= (int)steps.size();
}
