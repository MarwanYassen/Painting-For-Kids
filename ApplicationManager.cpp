#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSquareAction.h"
#include"Actions\AddTriangleAction.h"
#include"Actions\AddHexAction.h"
#include"Actions\AddCircleAction.h"
#include"Actions\SelectAction.h"
#include"Figures\CFigure.h"
#include "Actions\ChngBrdrClr.h"
#include "Actions\ChngFillClr.h"
#include "Actions\ChngtoBlack.h"
#include "Actions\ChngtoBlue.h"
#include "Actions\ChngtoGreen.h"
#include "Actions\ChngtoOrange.h"
#include "Actions\ChngtoRed.h"
#include "Actions\ChngtoYellow.h"
#include "Actions\Copy.h"
#include "Actions/Cut.h"
#include "Actions\Paste.h"
#include"Actions/SaveAction.h"
#include "Actions/LoadAction.h"
#include"Actions/SendBackAction.h"
#include"Actions/BringFrontAction.h"
#include "Actions\DeleteAction.h"
#include "Actions\ClearAll.h"
#include <iomanip> // For setw()
#include <fstream>
#include "Figures/CRectangle.h"
#include "Figures/CSquare.h"
#include "Figures/CCircle.h"
#include "Figures/CTriangle.h"
#include "Figures/CHexagon.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	SelectedCount = 0;

	RectCount = 0;
	SquCount = 0;
	TriCount = 0;
	CirCount = 0;
	HexaCount = 0;

	Clipboard = NULL;
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
	{
		FigList[i] = NULL;
		Selectedarr[i] = NULL;
	}
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT :
		pAct = new AddRectAction(this);
		break;

	case DRAW_SQU:
		pAct = new AddSquareAction(this);
		break;

	case DRAW_TRI:
		pAct = new AddTriangleAction(this);
		break;

	case DRAW_HEX:
		pAct = new AddHexAction(this);
		break;

	case DRAW_CIR:
		pAct = new AddCircleAction(this);
		break;

	case SELECT:
		pAct = new SelectAction(this);
		break;

	case BORDER:
		pAct = new ChngBrdrClr(this);
		break;

	case FILLING:
		pAct = new ChngFillClr(this);
		break;

	case CHANGETOBLACK:
		pAct = new ChngtoBlack(this);
		break;

	case CHANGETOBLUE:
		pAct = new ChngtoBlue(this);
		break;

	case CHANGETOGREEN:
		pAct = new ChngtoGreen(this);
		break;

	case CHANGETOORANGE:
		pAct = new ChngtoOrange(this);
		break;

	case CHANGETORED:
		pAct = new ChngtoRed(this);
		break;

	case CHANGETOYELLOW:
		pAct = new ChngtoYellow(this);
		break;

	case COPY:
		pAct = new Copy(this);
		break;

	case CUT:
		pAct = new Cut(this);
		break;

	case PASTE:
		pAct = new Paste(this);
		break;

	case SAVEGRAPH:
		pAct = new SaveAction(this);
		break;

	case LOADGRAPH:
		pAct = new LoadAction(this);
		break;

	case BRINGFRONT:
		pAct = new BringFrontAction(this);
		break;

	case SENDTOBACK:
		pAct = new SendBackAction(this);
		break;

	case DELET:
		pAct = new DeleteAction(this);
		break;

	case CLEARALL:
		pAct = new ClearAll(this);
		break;

	case EXIT:
		///create ExitAction here

		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
//////////////////////////////////////////////////////////////////////////
void ApplicationManager::DeleteFigure(CFigure* pFig)
{
	if (pFig != NULL) {
		for (int i = 0; i < SelectedCount; i++) {
			if (Selectedarr[i] == pFig) {
				Selectedarr[i] = Selectedarr[SelectedCount - 1];
				Selectedarr[SelectedCount - 1] = NULL;
				SelectedCount--;

				switch (pFig->getFigName()) {

				case CFigure::CIRCLE:
					CirCount--;
					break;

				case CFigure::HEXAGON:
					HexaCount--;
					break;

				case CFigure::RECTANGLE:
					RectCount--;
					break;

				case CFigure::SQUARE:
					SquCount--;
					break;

				case CFigure::TRIANGLE:
					TriCount--;
					break;

				}

				break; 
			}
		}
		for (int i = 0; i < FigCount; i++) {
			if (FigList[i] == pFig) {
				FigList[i] = FigList[FigCount - 1];
				FigList[FigCount - 1] = NULL;
				FigCount--;
				break;
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure** ApplicationManager::GetFigList() {
	return FigList;
}

string ApplicationManager::PrintInfo() const {
	int ID = 0;
	if (SelectedCount == 1) {
		for (int i = 0; i <= FigCount; i++) {
			if (FigList[i] == Selectedarr[0]) {
				ID = i+1;
				break;
			}
		}
	
		switch (Selectedarr[0]->getFigName()) {
	
		case CFigure::RECTANGLE: {
			CRectangle* RC = dynamic_cast<CRectangle*>(Selectedarr[0]);
			return ("Selected Figure is Rectangle, with ID of " + to_string(ID) + ", its Start point is ( " + to_string(RC->Xmin) + ", " + to_string(RC->Ymin) + " ) and its end point is( " + to_string(RC->Xmax) + ", " + to_string(RC->Ymax) + " ) , and its width = " + to_string(RC->dx) + ", and its height = " + to_string(RC->dy));
			break;
		}

		case CFigure::SQUARE: {
			CSquare* RS = dynamic_cast<CSquare*>(Selectedarr[0]);
			int Xstart = RS->Center.x - RS->L;
			int Ystart = RS->Center.y - RS->L;
			int Xend = RS->Center.x + RS->L;
			int Yend = RS->Center.y + RS->L;
			return ("Selected Figure is Square, with ID of " + to_string(ID) + ", its Start point is ( " + to_string(Xstart) + ", " + to_string(Ystart) + " ) and its end point is( " + to_string(Xend) + ", " + to_string(Yend) + " ) , and its side length = " + to_string(2 * RS->L));
			break;
		}

		case CFigure::CIRCLE: {
			CCircle* RI = dynamic_cast<CCircle*>(Selectedarr[0]);
			return("Selected Figure is Circle, With ID of " + to_string(ID) + ", its Center point is ( " + to_string(RI->point1.x) + ", " + to_string(RI->point1.y) + " ), and its radius = " + to_string(RI->radius));
			break;
		}

		case CFigure::TRIANGLE: {
			CTriangle* RT = dynamic_cast<CTriangle*>(Selectedarr[0]);
			return("Selected Figure is Triangle, With ID of " + to_string(ID) + ", its First Vertex is ( " + to_string(RT->vertex1.x) + ", " + to_string(RT->vertex1.y) + " ) and its Second Vertex is( " + to_string(RT->vertex2.x) + ", " + to_string(RT->vertex2.y) + " ) , and its Third Vertex is ( " + to_string(RT->vertex3.x) + ", " + to_string(RT->vertex3.y)+" )");
			break;
		}

		case CFigure::HEXAGON: {
			CHexagon* RH = dynamic_cast<CHexagon*>(Selectedarr[0]);
			return ("Selected Figure is Square, with ID of " + to_string(ID) + ", its Center point is ( " + to_string(RH->Center.x) + ", " + to_string(RH->Center.y) + " ) , and its side length = " + to_string(RH->L));
			break;
		}

		}
	}
	else if (SelectedCount > 1) {
		string message = ("Selected: ");
		if (RectCount != 0) {
			message += (to_string(RectCount) + " Rectangle(s), ");
		}
		if (SquCount != 0) {
			message += (to_string(SquCount) + " Square(s), ");
		}
		if (TriCount != 0) {
			message += (to_string(TriCount) + " Triangle(s), ");
		}
		if (HexaCount != 0) {
			message += (to_string(HexaCount) + " Hexagon(s), ");
		}
		if (CirCount != 0) {
			message += (to_string(CirCount) + " Circle(s), ");
		}
		return message;
	}
	else {
		return "";
	}
}

////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	for (int i = MaxFigCount - 1; i >= 0; i--) {
		if (FigList[i] != NULL && FigList[i]->SearchPoint(x, y)) {
			return FigList[i];
		}
	}
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
void ApplicationManager::BringFront(CFigure* shape) {
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] == shape) {
			CFigure* shapetemp = FigList[i];
			FigList[i] = FigList[FigCount - 1];
			FigList[FigCount - 1] = shapetemp;
			UpdateInterface();
		}

	}

}
void ApplicationManager::SendBack(CFigure* shape) {
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] == shape) {
			CFigure* shapetemp = FigList[i];
			FigList[i] = FigList[0];
			FigList[0] = shapetemp;
			UpdateInterface();
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::SetSelectedFig(CFigure* pFig) {
	if (pFig == NULL)
	{
		for (int i = 0; i < MaxFigCount; i++)
		{
			if (Selectedarr[i] != NULL && Selectedarr[i]->IsSelected() == false) {

				switch (Selectedarr[i]->getFigName()) {

				case CFigure::CIRCLE:
					CirCount--;
					break;

				case CFigure::HEXAGON:
					HexaCount--;
					break;

				case CFigure::RECTANGLE:
					RectCount--;
					break;

				case CFigure::SQUARE:
					SquCount--;
					break;

				case CFigure::TRIANGLE:
					TriCount--;
					break;

				}
				Selectedarr[i] = Selectedarr[SelectedCount - 1];
				Selectedarr[SelectedCount - 1] = NULL;
				SelectedCount--;
				break;
			}
		}
	}
	else
	{
		Selectedarr[SelectedCount] = pFig;
		switch (pFig->getFigName()) {

		case CFigure::CIRCLE:
			CirCount++;
			break;

		case CFigure::HEXAGON:
			HexaCount++;
			break;

		case CFigure::RECTANGLE:
			RectCount++;
			break;

		case CFigure::SQUARE:
			SquCount++;
			break;

		case CFigure::TRIANGLE:
			TriCount++;
			break;

		}
		SelectedCount++;
	}
}
///////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetSelectedFig() {
	if (Selectedarr[0] != NULL)
		return Selectedarr[0];
	else
		return NULL;
}
/////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::GetSelectedCount() {
	return SelectedCount;
}
/////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::DeselectAll()
{
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] != NULL)
			FigList[i]->SetSelected(false);
		Selectedarr[i] = NULL;
	}
	SelectedCount = 0;
	RectCount = 0;
	SquCount = 0;
	TriCount = 0;
	CirCount = 0;
	HexaCount = 0;
}
///////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::ClearFigures()
{
	for (int i = 0; i < MaxFigCount; i++) {
		FigList[i] = NULL;
		Selectedarr[i] = NULL;
	}
	FigCount = 0;
	SelectedCount = 0;
	RectCount = 0;
	SquCount = 0;
	TriCount = 0;
	CirCount = 0;
	HexaCount = 0;
}
//////////////////////////////////////////////////////////////////////////////////
CFigure::Name ApplicationManager::GetFigName() {
	return Selectedarr[0]->getFigName();
}
//////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::CopytoClipboard(CFigure* pFig) {
	Clipboard = pFig;
}
//////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetClipboard() {
	return Clipboard;
}
void ApplicationManager::SaveAll(ofstream& outFile) {
	outFile << left << setw(10) << FigList[0]->GetColorNameString(pOut->getCrntDrawColor()) << setw(10) << FigList[0]->GetColorNameString(pOut->getCrntFillColor()) << endl;
	outFile << FigCount << endl;
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->Save(outFile, i);
	}
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}

