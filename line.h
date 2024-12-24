#pragma once
#include "ofMain.h"
#include <vector>

class LineBrush {
public:
	LineBrush(); // constructor
	~LineBrush(); // destructor

	int size;
	int red;
	int green;
	int blue;
	int alpha;
	float x;
	float y;
	ofPolyline line;
	ofPoint pt;

	void draw(int red, int green, int blue, int alpha);
	void update(float x, float y, int size);
	void dragged(float x, float y);
	void released();
};