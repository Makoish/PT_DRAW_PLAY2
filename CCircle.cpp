#pragma once
#include "CCircle.h"

CCircle::CCircle(Point P1, double radii, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	radius = radii;

}

void CCircle::IsSelected() const
{

}
bool CCircle::checkCoordinates(double X, double Y) 
{
	float compare;
	compare = sqrt(pow(center.x - X, 2) + pow(center.y - Y, 2));
	if (compare <= radius)
	{
		Selected = 1;
		return true;
	}
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen

	pOut->DrawCircle(center, radius, FigGfxInfo, false);
}















