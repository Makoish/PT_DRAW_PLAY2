#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point p3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = p3;

}

void CTriangle::IsSelected() const
{

}
bool CTriangle::checkCoordinates(double x,double y)
{
	return true;
	Selected = 1;
}
void CTriangle::Draw(Output* pOut) const
{
	//Call Output::Drawtriangle to draw a rec on the screen

	pOut->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, false);
}