#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"
#include "..\Actions\SelectAction.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	ApplicationManager* pApp;
public:
	void IsSelected() const;
	virtual bool checkCoordinates(double, double);
	CRectangle(Point , Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

#endif