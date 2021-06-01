#pragma once
#include "CFigure.h"
#include "..\Actions\SelectAction.h"
class CCircle : public CFigure
{
private:
	Point center;
	double radius;
	ApplicationManager* pApp;
public:
	void IsSelected() const;
	CCircle(Point, double, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool checkCoordinates(double, double);
};