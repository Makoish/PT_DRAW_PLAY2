#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	DRAW_SQUR,      //DRAW SQUR
	CHNG_CLR,		//CHANGE COLOR
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	DEL,
	COPY,  //Delete a figure(s)
	PASTE,
	MOVE,			//Move a figure(s)
	RESIZE,	//Resize a figure(s)
	ROTATE,			//Rotate a figure(s)
	BACK,
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT, //Exit the application
	ZOOM_IN,
	ZOOM_OUT,
	Switch_play_mode,
	Switch_Draw_mode,
	size_half,
	size_quarter,
	size_double,
	size_fourth,

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar
	pickby_Area,
	pickby_Color,
	pickby_Type,
	pickby_both,
	figure,
	SELECT,

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY			//Switch interface to Play mode

	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif