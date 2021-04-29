#pragma once
#include <cmath>

#include "ofMain.h"
#include "FractalMode.h"
#include "CircleFractal.h"
#include "TreeFractal.h"
#include "SierpinskiFractal.h"
#include "CellularAutomata.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		// Made directly in header file since it needs to be defined before setup() call
		void setLevelColors(){
			colors.clear();
			for (int i = 0; i < ofGetHeight(); i++) {
				colors.push_back(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));
			}
		}
		
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
		int levels = 4;
		long timer = 0;
		int check = 0;
	private:
		bool play = false;
		vector<ofColor> colors;
		vector<FractalMode*> fractals = {new CircleFractal(), new TreeFractal(), new SierpinskiFractal(), new CellularAutomata()};
};

