#include "SierpinskiFractal.h"

void SierpinskiFractal::draw(float x, float y, float size, int n, unsigned int icolor, vector<ofColor> colors) {
    if(n == 0) {
        return;
    }

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    if (icolor >= colors.size()) icolor = 0;
    ofSetColor(colors[icolor]);
    ofDrawTriangle(a, b, c);

    this->draw(x, y, size / 2, n - 1, icolor+1, colors);
    this->draw((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1, icolor+1, colors);
    // 2.5 unfinished
    this->draw((a.x + c.x) / 2, (a.y + c.y) / 2, size / 2, n - 1, icolor+1, colors);
}