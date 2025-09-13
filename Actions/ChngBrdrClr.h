#pragma once
#include "Action.h"
class ChngBrdrClr : public Action
{
public: 
	ChngBrdrClr(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};
