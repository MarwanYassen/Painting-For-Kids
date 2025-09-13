#ifndef BRING_FRONT_ACTION_H
#define BRING_FRONT_ACTION_H
#include "Action.h"
#include "../Figures/CFigure.h"
class BringFrontAction : public Action
{
private:
	Point P1;
	CFigure* shape;
public:
	BringFrontAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};
#endif