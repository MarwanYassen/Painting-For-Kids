#ifndef SAVE_GRAPH_H
#define SAVE_GRAPH_H

#include "Action.h"
#include <fstream>
class SaveAction : public Action
{
private:
	string filename;
public:
	SaveAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};

#endif