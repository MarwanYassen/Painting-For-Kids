#pragma once
#include "Action.h"
class ChngtoGreen : public Action
{
public:
	ChngtoGreen(ApplicationManager* pApp);

	void ReadActionParameters();

	void Execute();
};

