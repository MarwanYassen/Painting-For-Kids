#pragma once
#include "Action.h"
class AddSquareAction : public Action
{
private:
	Point P1;
	GfxInfo SquGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

