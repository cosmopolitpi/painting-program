#pragma once

#include "ofMain.h"
#include <vector>
#include "ofxGui.h"
#include "paint.h"
#include "line.h"
#include "dynamicbrush.h"

class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);

		bool mouseIsPressed;
		//following two functions have not been moved to classes as they are too simple
		void eraser(float x, float y, int size);
		void tri(float x, float y);
		float tRotate; //variable used for triangle brush
		//declaring dynamic brush class object
		dynamicBrush DB;
		//declaring line brush class object
		LineBrush LBrush;

		//vector<LineBrush> myLineBrush; //used for test adding and removing objects from vector array but does not work with ofSetBackgroundAuto(false) so code is commented

		//selection of brushes via enum variable
		enum selection { PaintBrush, TriangleBrush, LineBrush, Eraser, Dbrush }selbrush;

		//Gui
		ofxPanel gui;
		ofxFloatSlider size;
		ofxFloatSlider red;
		ofxFloatSlider green;
		ofxFloatSlider blue;
		ofxFloatSlider alpha;

	private:

};
