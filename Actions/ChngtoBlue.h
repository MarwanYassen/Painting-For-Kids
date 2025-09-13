#pragma once
#include "Action.h"
class ChngtoBlue : public Action
{
public:
	ChngtoBlue(ApplicationManager* pApp);

	void ReadActionParameters();

	void Execute();
};
