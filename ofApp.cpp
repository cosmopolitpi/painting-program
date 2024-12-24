#include "ofApp.h"
#include <iostream>
#include <vector>

//Custom designed abstract painting program written by Hristo Yordanov / Cosmopolit Design 2020-2021

using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetBackgroundAuto(false);
	ofEnableAlphaBlending();

	//initial state of for paint tools booleans draws on canvas when mouse is pressed
	mouseIsPressed = false;

	ofBackground(0,0,0); // clear the screen with a black color
	ofEnableAntiAliasing(); // smooth lines
	ofSetCircleResolution(50); // For smoother looking circles + ellipses
	ofSetFrameRate(60); //this is a speed limit fps

	
	DB.setup();
	tRotate = 1;

	//GUI
	gui.setup();
	gui.setPosition(810,10);
	//labeling the sliders with the strings, starting the inital value, and giving the sliders a range. 
	gui.add(size.setup("brush size", 100, 1, 300));
	gui.add(red.setup("red", 140, 0, 255));
	gui.add(green.setup("green", 140, 0, 255));
	gui.add(blue.setup("blue", 140, 0, 255));
	gui.add(alpha.setup("transparency", 50, 0, 255));
	
}

//--------------------------------------------------------------
void ofApp::update(){

	LBrush.update(ofGetMouseX(), ofGetMouseY(), size);
	DB.update();

}

//--------------------------------------------------------------
void ofApp::draw() {

	//UI panel - first paint brush
	ofSetColor(20, 20, 20, 80);
	ofDrawRectangle(0, 0, 1024, 140); //background on UI
	ofSetColor(200);
	ofNoFill(); // the shapes will be no filled
	ofSetLineWidth(2.0); // A higher value will render thicker lines
	ofDrawRectangle(10, 10, 100, 100);
	ofFill();
	ofSetColor(255, 255, 0);
	ofDrawEllipse(60, 60, 20, 20);
	//drawing selection line that display current used brush
	ofSetColor(0, 200, 255);
	if (selbrush == 0) {
		ofDrawLine(20, 100, 100, 100);
	}
	ofSetColor(255);
	ofDrawBitmapString("Press key 'd'", 10, 133);

	//UI panel - selected color
	ofSetColor(200);
	ofSetLineWidth(2.0); // A higher value will render thicker lines
	ofSetColor(red, green, blue);
	ofDrawRectangle(690, 10, 100, 50);
	ofSetColor(red, green, blue, alpha);
	ofDrawRectangle(690, 60, 100, 50);

	//second brush - triangle of UI
	ofSetColor(200);
	ofNoFill(); // the shapes will be no filled
	ofSetLineWidth(2.0); // A higher value will render thicker lines
	ofDrawRectangle(120, 10, 100, 100);
	ofSetColor(200, 0, 100);
	ofNoFill(); // the shapes will be no filled
	ofSetLineWidth(3.2); // A higher value will render thicker lines
	ofDrawTriangle(170 - 20, 50 + 20, 170, 50, 170 + 20, 50 + 20);
	ofSetColor(0, 200, 255);
	if (selbrush == 1) {
		ofDrawLine(130, 100, 210, 100);
	}
	//draw key press keys
	ofSetColor(255);
	ofDrawBitmapString("Press key 'd'", 10, 133);
	ofDrawBitmapString("key 't'", 140, 133);
	ofDrawBitmapString("key 'l'", 250, 133);
	ofDrawBitmapString("key 'e'", 360, 133);
	ofDrawBitmapString("key 'b'", 470, 133);
	ofDrawBitmapString("key 's'", 580, 133);
	ofDrawBitmapString("colour", 715, 133);

	//third brush - line of UI
	ofSetColor(200);
	ofNoFill(); // the shapes will be no filled
	ofSetLineWidth(2.0); // A higher value will render thicker lines
	ofDrawRectangle(230, 10, 100, 100);
	ofSetColor(0, 255, 0);
	ofNoFill(); // the shapes will be no filled
	ofSetLineWidth(3.2); // A higher value will render thicker lines
	ofDrawLine(280 - 20, 60, 280 + 20, 60);
	ofSetColor(0, 200, 255);
	if (selbrush == 2) {
		ofDrawLine(240, 100, 320, 100);
	}

	//eraser brush of UI
	ofSetColor(200);
	ofNoFill(); // the shapes will be no filled
	ofSetLineWidth(2.0); // A higher value will render thicker lines
	ofDrawRectangle(340, 10, 100, 100);
	ofDrawEllipse(390, 60, 50, 50);
	ofSetColor(0, 200, 255);
	if (selbrush == 3) {
		ofDrawLine(350, 100, 430, 100);
	}

	//dynamic brush of UI
	ofSetColor(200);
	ofNoFill(); // the shapes will be no filled
	ofSetLineWidth(2.0); // A higher value will render thicker lines
	ofDrawRectangle(450, 10, 100, 100);
	ofSetColor(0, 100, 255);
	ofFill();
	ofDrawRectangle(485, 45, 30, 30);
	ofSetColor(0, 200, 255);
	if (selbrush == 4) {
		ofDrawLine(460, 100, 540, 100);
	}

	//SAVE of UI
	ofSetColor(200);
	ofNoFill(); // the shapes will be no filled
	ofSetLineWidth(2.0); // A higher value will render thicker lines
	ofDrawRectangle(560, 10, 100, 100);
	ofSetColor(200);
	ofDrawBitmapString("SAVE", 595, 65);


	ofFill(); // If I omit this and leave ofNoFill(), all the shapes will be outlines
	//if statements to call functions and paint tools
	if (mouseIsPressed && (selbrush == 0)) {
		Paint(ofGetMouseX(), ofGetMouseY(), size, red, green, blue, alpha);
	}
	else if (mouseIsPressed && (selbrush == 3)) {
		eraser(ofGetMouseX(), ofGetMouseY(), size);
	}
	else if (mouseIsPressed && (selbrush == 2)) {
		LBrush.draw(red, green, blue, alpha);
		//myLineBrush.push_back(LBrush);
	}

	else if (mouseIsPressed && (selbrush == 1)) {
		tri(ofGetMouseX(), ofGetMouseY());
	}

	else if (mouseIsPressed && (selbrush == 4)) {
		DB.draw(red, green, blue, alpha, ofGetMouseX(), ofGetMouseY(), size, DB.brushState);
	}

	else {

	}

	//for (LineBrush LBrush : myLineBrush) {
	//	LBrush.draw(red, green, blue, alpha);
	//}

	ofSetColor(255);
	gui.draw();

	//cout << DB.brushState << endl;
	//cout << "New size: " << myLineBrush.size() << endl;
	//cout << "Selected brush: " << selbrush << endl;
}

void ofApp::eraser(float x, float y, int size) {
	ofSetColor(0, alpha);
	ofDrawCircle(x, y, size);
}

void ofApp::tri(float x, float y) {
	ofSetColor(red, green, blue, alpha);
	ofNoFill(); // the shapes will be no filled
	ofSetLineWidth(3.2); // A higher value will render thicker lines
	ofPushMatrix();

	if (tRotate < 150) {
		tRotate = tRotate + 0.3;
	}
	ofDrawTriangle(ofGetMouseX() - size, ofGetMouseY() + size - tRotate, ofGetMouseX() + tRotate, ofGetMouseY() - tRotate, ofGetMouseX() + size - tRotate, ofGetMouseY() + size); // Three corners.
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//when keys are pressed certain brushes get selected
	//activate eraser
	if (key == 'e') {
		selbrush = Eraser;
	}
	//activate paint lines
	if (key == 'l') {
		selbrush = LineBrush;
	}
	//paint triangles
	if (key == 't') {
		selbrush = TriangleBrush;
	}
	//default paintbrush
	if (key == 'd') {
		selbrush = PaintBrush;
	}
	//dynamic brush
	if (key == 'b') {
		selbrush = Dbrush;
	}
	//colour picker
	if (key == 'p') {

	}

	//if (key == 'r') {
	//	if (!myLineBrush.empty())
	//	{
	//		myLineBrush.pop_back();
	//	}
	//}
	
	//saving image in PNG format of current screen drawing
	if (key == 's') {
		glReadBuffer(GL_FRONT);  //when using ofSetAutoBackground(false)
		ofSaveScreen("savedScreenshot_" + ofGetTimestampString() + ".png"); //grabs the current screen and saves it to a file inside of project's ./bin/data/
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	LBrush.dragged(ofGetMouseX(), ofGetMouseY());
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	mouseIsPressed = true;
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	mouseIsPressed = false;
	LBrush.released();
	tRotate = 1;
}