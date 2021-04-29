#include "CircleFractal.h"

void CircleFractal::draw(int x, int y, int n, unsigned int icolor, vector<ofColor> colors) {
    if(n!=0){
        if (icolor >= colors.size()) icolor = 0;
        ofSetColor(colors[icolor]);
        ofDrawCircle(x, y, 100 - 100/(n+1));
        this->draw(x+100, y, n-1, icolor+1, colors);
        this->draw(x-100, y, n-1, icolor+1, colors);
        this->draw(x, y+100, n-1, icolor+1, colors);
        this->draw(x, y-100, n-1, icolor+1, colors);
    }
}