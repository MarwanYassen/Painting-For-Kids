#ifndef SEND_BACK_ACTION_H
#define SEND_BACK_ACTION_H

#include "Action.h"
#include "../Figures/CFigure.h"

class SendBackAction : public Action
{
private:
	Point P1;
	CFigure *shape;
public:
	SendBackAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};

#endif