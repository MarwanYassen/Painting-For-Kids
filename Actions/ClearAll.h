#pragma once
#include "Action.h"
class ClearAll : public Action
{
private:
	Point* P;
public:
	ClearAll(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	~ClearAll();
};

