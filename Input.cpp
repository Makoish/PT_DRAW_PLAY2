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

string Input::GetSrting(Output* pO) const
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
		if (Key == 8)	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
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
			case ITM_Pick_Figure: return figure;
			case ITM_Delete: return DEL;
			case ITM_COPY: return COPY;
			case ITM_PASTE: return PASTE;
			case ITM_MOVE: return MOVE;
			case ITM_SAVE: return SAVE;
			case ITM_EXIT: return EXIT;
			case ITM_LOAD: return LOAD;
			case ITM_SELECT: return SELECT;
			case ITM_zoomin: return ZOOM_IN;
			case ITM_zoomout: return ZOOM_OUT;
			case ITM_SWITCH_PLAY_MODE: return TO_PLAY;
			case ITM_Resize: return RESIZE;
			case ITM_Change_Color: return CHNG_CLR;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		return STATUS;

	}
	if (UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_PickbyAREA: return pickby_Area;
			case ITM_Pickbycolor: return pickby_Color;
			case ITM_Pickbyboth: return pickby_both;
			case ITM_Pickbytype: return pickby_Type;
			case ITM_SWITCH_DRAW_MODE: return TO_DRAW;
			case ITM_EXIT_PLAY: return EXIT;
			case ITM_SAVE_PLAY: return SAVE;
			case ITM_LOAD_PLAY: return LOAD;

			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		return STATUS;


	}
	if (UI.InterfaceMode == MODE_Figure)
	{

		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_LINE: return DRAW_LINE;
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_TRI: return DRAW_TRI;
			case ITM_BACK2: return BACK;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		return STATUS;
	}
	if (UI.InterfaceMode == MODE_RESIZE)
	{

		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_Half: return size_half;
			case ITM_Quarter: return size_quarter;
			case ITM_Twice: return size_double;
			case ITM_Fourth: return size_fourth;
			case ITM_BACK: return BACK;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		return STATUS;
	}
	if (UI.InterfaceMode == MODE_CHANGE_COLOR)
	{

		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_change_background_color: return CHNG_BK_CLR;
			case ITM_change_draw_color: return CHNG_DRAW_CLR;
			case ITM_Change_filling_color: return CHNG_FILL_CLR;
			case ITM_BACK1: return BACK;
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		return STATUS;


	}

}

/////////////////////////////////

Input::~Input()
{
}