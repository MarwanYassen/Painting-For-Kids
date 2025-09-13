#include "SaveAction.h"

#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter File name: ");
	filename =  pIn->GetString(pOut);
}

//Execute the action
void SaveAction::Execute()
{
	ReadActionParameters();
	ofstream outFile;
	outFile.open(filename, ios::out);
	pManager->SaveAll(outFile);
	outFile.close();
	pManager->GetOutput()->PrintMessage("File Saved");
}