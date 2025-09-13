#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures

class CFigure
{
public:
	enum Name { RECTANGLE, SQUARE, CIRCLE, TRIANGLE, HEXAGON };
	CFigure() {};
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	bool IsCut;                 //True when figure has been cut

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure

	void setChngBrdr(bool b);       //Flag to change border color when pressing on a color
	bool getChngBrdr();             //true when you press change border clr
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void setChngFill(bool b);       //Flag to change fill color when pressing on a color
	bool getChngFill();             //true when you press change fill clr
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	GfxInfo GetGfxInfo();
	Name getFigName();
	virtual CFigure* deepcopy() = 0;  //deep copies the selected figure
	virtual bool SearchPoint(int x, int y) = 0;

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream& OutFile, int i) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile, int line, Output*) = 0;	//Load the figure parameters to the file

	string GetColorNameString(color);
	color GetColorFromString(string);

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	Name FigName;
	bool ChngBrdr;
	bool ChngFill;

	/// Add more parameters if needed.

};

#endif