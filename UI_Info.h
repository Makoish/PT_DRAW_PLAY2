#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_Figure,
	MODE_RESIZE,
	MODE_CHANGE_COLOR,
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_Pick_Figure,
	ITM_SELECT,
	ITM_Delete,
	ITM_COPY,
	ITM_Resize,
	ITM_MOVE,
	ITM_Change_Color,
	ITM_PASTE,
	ITM_LOAD,
	ITM_SAVE,
	ITM_zoomin,
	ITM_zoomout,
	ITM_SWITCH_PLAY_MODE,
	//TODO: Add more items names here
	ITM_EXIT,		//Exit item

	DRAW_ITM_COUNT,		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	ITM_PickbyAREA,
	ITM_Pickbyboth,
	ITM_Pickbycolor,
	ITM_Pickbytype,
	ITM_SAVE_PLAY,
	ITM_LOAD_PLAY,
	ITM_SWITCH_DRAW_MODE,
	ITM_EXIT_PLAY,
	PLAY_ITM_COUNT,
};

enum FigureMenuItem //The items of the Play menu (you should add more items)
{
	ITM_RECT,
	ITM_CIRC,
	ITM_LINE,
	ITM_TRI,
	ITM_BACK2,
	DRAW_ITM_COUNT_FIGURE,		//no. of menu items ==> This should be the last line in this enum
};
enum ChangeColorMenuItem
{
	ITM_Change_filling_color,
	ITM_change_background_color,
	ITM_change_draw_color,
	ITM_BACK1,
	CHANGE_COLOR_ITM_COUNT,
};
enum ResizeMenuItem
{
	ITM_Half,
	ITM_Quarter,
	ITM_Twice,
	ITM_Fourth,
	ITM_BACK,
	RESIZE_ITM_COUNT,
};
__declspec(selectany) //This line to prevent "redefinition error"
struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color ToolBarColor;
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif