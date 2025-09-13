#pragma once
#include "Action.h"
class Cut : public Action
{
public: 
	Cut(ApplicationManager* pApp);

	void ReadActionParameters();

	void Execute();
};

