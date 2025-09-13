#pragma once
#include "Action.h"
class ChngtoBlack : public Action
{
public: 
	ChngtoBlack(ApplicationManager* pApp);

	void ReadActionParameters();

	void Execute();
};

