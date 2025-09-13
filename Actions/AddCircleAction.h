#pragma once
#include "Action.h"
class AddCircleAction : public Action
{
private:
	Point P1;
	Point P2;
	GfxInfo CirGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

