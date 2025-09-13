#include "Copy.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


Copy::Copy(ApplicationManager* pApp): Action(pApp){}

void Copy::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	if (pManager->GetSelectedFig() != NULL)
		pOut->PrintMessage("Figure copied to clipboard");
      else
		pOut->PrintMessage("No figure is selected");
}

void Copy::Execute() {
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (pManager->GetSelectedCount() == 1)
	{
		pManager->CopytoClipboard(pManager->GetSelectedFig()->deepcopy());
	}
	else if (pManager->GetSelectedCount() > 1)
		pOut->PrintMessage("Select only one figure");
}