#pragma once
#include "ofMain.h"
#include <vector>

class Paint {
public:
	Paint(float x, float y, int size, int red, int green, int blue, int alpha); // constructor
	~Paint(); // destructor

	int size;
	int red;
	int green;
	int blue;
	int alpha;
	float x;
	float y;
	int maxRadius = 100;  // Increase for a wider brush
	int radiusStepSize = 10;  // Decrease for more circles (i.e. a more opaque brush)
	int maxOffsetDistance = 50;  // Increase for a larger spread of circles
	// draw smaller and smaller circles and layering (increasing) opaqueness
	float angle = ofRandom(ofDegToRad(360.0));
	float distance = ofRandom(maxOffsetDistance);
	float xOffset = cos(angle) * distance;
	float yOffset = sin(angle) * distance;
};