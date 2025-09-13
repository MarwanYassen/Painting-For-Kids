#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
void Input::GetPointClickeddraw(int& x, int& y) const
{
	do
		pWind->WaitMouseClick(x, y);	//Wait for mouse click
	while (y<UI.ToolBarHeight || y>(UI.height - UI.StatusBarHeight));
}
string Input::GetString(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE: return DRAW_SQU;
			case ITM_TRIANGLE:return DRAW_TRI;
			case ITM_HEXAGON:return DRAW_HEX;
			case ITM_CIRCLE:return DRAW_CIR;
			case ITM_BLACK:return CHANGETOBLACK;
			case ITM_YELLOW:return CHANGETOYELLOW;
			case ITM_ORANGE:return CHANGETOORANGE;
			case ITM_RED:return CHANGETORED;
			case ITM_GREEN:return CHANGETOGREEN;
			case ITM_BLUE:return CHANGETOBLUE;
			case ITM_BORDER:return BORDER;
			case ITM_FILLING:return FILLING;
			case ITM_SELECT:return SELECT;
			case ITM_CLEAR:return CLEARALL;
			case ITM_DELETE:return DELET;
			case ITM_CUT:return CUT;
			case ITM_COPY:return COPY;
			case ITM_PASTE:return PASTE;
			case ITM_SEND:return SENDTOBACK;
			case ITM_BRING:return BRINGFRONT;
			case ITM_SAVE:return SAVEGRAPH;
			case ITM_LOAD:return LOADGRAPH;
			case ITM_SWITCH:return TO_PLAY;
			case ITM_EXIT: return EXIT;

			default: return DRAW_EMPTY;	//A click on empty place in design toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight) {
			int ClickedItemOrder = (x / 80);
			switch (ClickedItemOrder)
			{

			case PLAY_ITM_FIG: return PICKTYPE;
			case PLAY_ITM_FILL:return PICKCOLOR;
			case PLAY_ITM_BOTH:return PICKTYPECOLOR;
			case PLAY_ITM_RESTART:return RESTART;
			case PLAY_ITM_SWITCH: return TO_DRAW;
			case PLAY_ITM_EXIT: return EXIT;
			default: return PLAY_EMPTY;	//A click on empty place in play toolbar
			}
		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return PLAY_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
	}

}
/////////////////////////////////

Input::~Input()
{
}
