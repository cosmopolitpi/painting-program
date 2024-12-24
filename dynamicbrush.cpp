#include "dynamicbrush.h"
#include <iostream>

dynamicBrush::dynamicBrush()
{

}

dynamicBrush::~dynamicBrush()
{
	// destructor
}

void dynamicBrush::draw(int red, int green, int blue, int alpha, float x, float y, int size, char brushState)
{
	ofSetColor(red, green, blue, alpha);
	if (brushState == 0)
	{
		ofDrawRectangle(x - (brushState / 2), y - (brushState / 2), brushState, brushState);
	}
	else if (brushState == 1)
	{
		ofDrawRectangle(x - (size / brushState / 2), y - (size / brushState / 2), size / brushState, size / brushState);
	}
	else if (brushState == 2)
	{
		ofDrawRectangle(x - (size * brushState / 2), y - (size * brushState / 2), size * brushState, size * brushState);
	}
	else if (brushState == 3)
	{
		ofDrawRectangle(x - (size * brushState / 2), y - (size * brushState / 2), size * brushState, size * brushState);
	}
}

void dynamicBrush::update()
{
	// iterate 0-4 then back to 0
	dynamicBrushState = (dynamicBrushState + 1) % 4;
	brushState = dynamicBrushState;
}

void dynamicBrush::setup()
{
	dynamicBrushState = 30;
}