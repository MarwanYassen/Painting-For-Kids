#pragma once
#include "Action.h"
class AddHexAction : public Action
{
private:
	Point P1;
	GfxInfo HexGfxInfo;
public:
	AddHexAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

