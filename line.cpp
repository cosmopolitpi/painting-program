#include "line.h"
#include <iostream>

LineBrush::LineBrush()
{

}

LineBrush::~LineBrush()
{
	// destructor
}

void LineBrush::draw(int red, int green, int blue, int alpha)
{
	ofSetColor(red, green, blue, alpha);
	line.draw();
}

void LineBrush::update(float x, float y, int size)
{
	//slight random variations of vert to create dynamic changing line 
	for (auto &vert : line.getVertices()) {
		vert.x += ofRandom(- size, + size);
		vert.y += ofRandom(- size, + size);
	}
}

void LineBrush::dragged(float x, float y)
{
	pt.set(x, y);
	line.addVertex(pt);
}

void LineBrush::released()
{
	line.clear();
}