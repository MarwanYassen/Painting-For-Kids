#pragma once
#include "Action.h"
class ChngtoOrange : public Action
{
public:
	ChngtoOrange(ApplicationManager* pApp);

	void ReadActionParameters();

	void Execute();
};

