#include "ChngtoRed.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Actions\SelectAction.h"

ChngtoRed::ChngtoRed(ApplicationManager* pApp) : Action(pApp) {}

void ChngtoRed::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig() == NULL)
		pOut->PrintMessage("No figure is selected");
	else
		pOut->PrintMessage("Color changed to red");
}

void ChngtoRed::Execute() {
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (pManager->GetSelectedFig()->getChngBrdr())
	{
		pManager->GetSelectedFig()->ChngDrawClr(RED);
		pManager->GetSelectedFig()->setChngBrdr(false);
	}
	else if (pManager->GetSelectedFig()->getChngFill())
	{
		pManager->GetSelectedFig()->ChngFillClr(RED);
		pManager->GetSelectedFig()->setChngFill(false);
	}
	else
		pOut->PrintMessage("Please press change fill or change border first");
}