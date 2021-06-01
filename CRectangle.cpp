#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	
}

void CRectangle::IsSelected() const
{
	
}
bool CRectangle::checkCoordinates(double X,double Y)
{
	return true;

}
void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen
	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, false);
}
