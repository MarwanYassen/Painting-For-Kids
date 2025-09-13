#ifndef LOAD_GRAPH_H
#define LOAD_GRAPH_H

#include "Action.h"

class LoadAction : public Action
{
private:
	string filename;
public:
	LoadAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};

#endif

