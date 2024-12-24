#include "paint.h"
#include <iostream>

Paint::Paint(float x, float y, int size, int red, int green, int blue, int alpha)
{
	for (int radius = maxRadius; radius > 0; radius -= radiusStepSize) {
		ofSetColor(red + xOffset, green, blue, alpha);
		ofDrawCircle(x + xOffset, y + yOffset, size, size);
	}
}

Paint::~Paint()
{
	// destructor
}
