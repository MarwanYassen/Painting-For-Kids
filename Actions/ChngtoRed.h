#pragma once
#include "Action.h"
class ChngtoRed : public Action
{
public:
	ChngtoRed(ApplicationManager* pApp);

	void ReadActionParameters();

	void Execute();
};
