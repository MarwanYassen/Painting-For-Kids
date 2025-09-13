#pragma once
#include "Action.h"
class ChngFillClr : public Action
{
public:
	ChngFillClr(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

