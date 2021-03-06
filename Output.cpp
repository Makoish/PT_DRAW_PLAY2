#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1300;
	UI.height = 700;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 80;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateFigureToolBar() const
{
	UI.InterfaceMode = MODE_Figure;
	string MenuItemImages[DRAW_ITM_COUNT_FIGURE];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\line.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_tri.jpg";
	MenuItemImages[ITM_BACK2] = "images\\MenuItems\\back.jpg";



	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT_FIGURE; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_Pick_Figure] = "images\\MenuItems\\PickFigure.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\copy.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\paste.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_SWITCH_PLAY_MODE] = "images\\MenuItems\\Menu_play.jpg";
	MenuItemImages[ITM_Resize] = "images\\MenuItems\\resize.jpg";
	MenuItemImages[ITM_Delete] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_zoomin] = "images\\MenuItems\\zoom-in.jpg";
	MenuItemImages[ITM_zoomout] = "images\\MenuItems\\zoom-out.jpg";
	MenuItemImages[ITM_Change_Color] = "images\\MenuItems\\change current color.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\select.jpg";







	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateResizeToolBar() const
{
	UI.InterfaceMode = MODE_RESIZE;
	string MenuItemImages[RESIZE_ITM_COUNT];
	MenuItemImages[ITM_Half] = "images\\MenuItems\\half.jpg";
	MenuItemImages[ITM_Quarter] = "images\\MenuItems\\quarter.jpg";
	MenuItemImages[ITM_Twice] = "images\\MenuItems\\Twice.jpg";
	MenuItemImages[ITM_Fourth] = "images\\MenuItems\\fourth.jpg";
	MenuItemImages[ITM_BACK] = "images\\MenuItems\\back.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < RESIZE_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}
void Output::CreateChangeColorToolBar() const
{
	UI.InterfaceMode = MODE_CHANGE_COLOR;
	string MenuItemImages[CHANGE_COLOR_ITM_COUNT];
	MenuItemImages[ITM_Change_filling_color] = "images\\MenuItems\\fillcolor.jpg";
	MenuItemImages[ITM_change_background_color] = "images\\MenuItems\\backgroundcolour.jpg";
	MenuItemImages[ITM_change_draw_color] = "images\\MenuItems\\drawcolor.jpg";
	MenuItemImages[ITM_BACK1] = "images\\MenuItems\\back.jpg";
	//Draw menu item one image at a time
	for (int i = 0; i < CHANGE_COLOR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_SAVE_PLAY] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD_PLAY] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_PickbyAREA] = "images\\MenuItems\\PickbyAREA.jpg";
	MenuItemImages[ITM_Pickbyboth] = "images\\MenuItems\\Pickbyboth.jpg";
	MenuItemImages[ITM_Pickbycolor] = "images\\MenuItems\\Pickbycolor.jpg";
	MenuItemImages[ITM_Pickbytype] = "images\\MenuItems\\Pickbytype.jpg";
	MenuItemImages[ITM_SWITCH_DRAW_MODE] = "images\\MenuItems\\ToDraw.jpg";
	MenuItemImages[ITM_EXIT_PLAY] = "images\\MenuItems\\Menu_Exit.jpg";




	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////


void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessageSpecial(string msg) const	//Prints a message on status bar , it's a spicial function to print the string entered from the user.
{
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(160, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);

}

void Output::PrintMessageSpecial2(string msg) const	//Prints a message on status bar , it's a spicial function to print the string entered from the user.
{
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}


color Output::getCrntDrawColor() const	//get current drwawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (LineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(LineGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
}
void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriangleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}
void Output::DrawCircle(Point P1, const int radius, GfxInfo circleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = circleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, circleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (circleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(circleGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawCircle(P1.x, P1.y, radius, style);
}
void Output::ClearToolBar() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, 1300, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}