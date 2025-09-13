#include "LoadAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../Figures/CCircle.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CHexagon.h"
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{}

void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter File name: ");
	filename = pIn->GetString(pOut);

}

//Execute the action
void LoadAction::Execute()
{
	ReadActionParameters();
	ifstream inFile;
	inFile.open(filename, ios::in);
	inFile.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
	inFile.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');//igonring first two lines
	string line;
		//looping through lines
	int numline = 1;
	pManager->ClearFigures();
	while (getline(inFile, line)) {
		// Process the line
		numline++;
		string shapeName = line.substr(0,10);//getting name
		CFigure* shape;
		if (shapeName == "Triangle  ")
			shape = new CTriangle();
		else if (shapeName == "Circle    ")
			shape = new CCircle();
		else if (shapeName == "Rectangle ")
			shape = new CRectangle();
		else if (shapeName == "Hexagon   ")
			shape = new CHexagon();
		else if (shapeName == "Square    ")
			shape = new CSquare();
		else
				break;
		shape->Load(inFile, numline,pManager->GetOutput());
		pManager->AddFigure(shape);
	}
	inFile.close();
	pManager->GetOutput()->PrintMessage("File Loaded");
}