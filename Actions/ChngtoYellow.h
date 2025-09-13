#pragma once
#include "Action.h"
class ChngtoYellow :  public Action
{
public:
	ChngtoYellow(ApplicationManager* pApp);

	void ReadActionParameters();

	void Execute();
};

