#pragma once
#include "ofMain.h"

class dynamicBrush {
public:
	dynamicBrush(); // constructor
	~dynamicBrush(); // destructor

	int dynamicBrushState;
	int brushState;

	int size;
	int red;
	int green;
	int blue;
	int alpha;
	float x;
	float y;

	void draw(int red, int green, int blue, int alpha, float x, float y, int size, char brushState);
	void update();
	void setup();
};