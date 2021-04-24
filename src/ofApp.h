#pragma once
#include<cmath>

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		// Made directly in header file since used in needs to be defined before setup() call
		void setLevelColors(){
			colors.clear();
			for (int i = 0; i < ofGetHeight(); i++) {
				colors.push_back(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));
			}
		}
		
		void drawMode1(int x, int y, int n, unsigned int icolor);
		void drawMode2(int length, int n, int x, int y, int d, unsigned int icolor);
		void drawMode3(float x, float y, float size, int n, unsigned int icolor);
		void drawMode4(int x, int y, int n, unsigned int icolor);
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		int levels;
	private:
		bool mode1 = true;
		bool mode2 = false;
		bool mode3 = false;
		bool mode4 = false;
		vector<ofColor> colors;
};

