#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "Actions\AddSquareAction.h"
#include"Actions\AddTriangleAction.h"
#include"Actions\AddHexAction.h"
#include"Actions\AddCircleAction.h"
#include"Actions\SelectAction.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	int SelectedCount;      //Number of selected figures

	//Number fo selected figures according to type
	int RectCount;
	int SquCount;
	int HexaCount;
	int CirCount;
	int TriCount;


	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	CFigure* Clipboard;  //Pointer to copied/cut figure

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void DeleteFigure(CFigure* pFig);       //Delete figures from fig list
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void SaveAll(ofstream& outFile);
	void SetSelectedFig(CFigure* pFig);
	CFigure* GetSelectedFig();              //return pointer of last selected figure
	int GetSelectedCount();                 //return count of selected figures
	void DeselectAll();                     //unselect all figures
	void ClearFigures();                   //clear all figures
	CFigure::Name GetFigName();
	void CopytoClipboard(CFigure* pFig);
	CFigure* GetClipboard();
	void SendBack(CFigure*);
	void BringFront(CFigure*);
	CFigure* Selectedarr[MaxFigCount]; //Array of all selected figures
	CFigure** GetFigList();
	string PrintInfo() const;                 //print the info of selected figure in the status bar

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

};

#endif