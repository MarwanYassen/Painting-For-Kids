#pragma once
#include "Action.h"
class Copy : public Action
{
public:
	Copy(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

