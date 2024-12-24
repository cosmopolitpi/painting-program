#include "ofMain.h"
#include "ofApp.h"
//Custom designed abstract painting program written by Hristo Yordanov / Cosmopolit Design 2020-2021
//========================================================================
int main( ){
	ofSetupOpenGL(1920,1080,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
