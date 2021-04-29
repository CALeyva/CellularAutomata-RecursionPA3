#include "TreeFractal.h"

// int d
void TreeFractal::draw(int length, int n, int x, int y, int d, unsigned int icolor, vector<ofColor> colors) {
    if(n != 0){
        int middleY = y-length;
        int leftBranchX = x -length*cos(PI/180*(rand() % 20 + 15));
        int leftBranchY = middleY -length*sin(PI/180*(rand() % 20 + 15));  //Implemented randomized branch angles, with a range from 30° to 70°. 
        int rightBranchX = x +length*cos(PI/180*(rand() % 20 + 15));
        int rightBranchY = middleY -length*sin(PI/180*(rand() % 20 + 15));

        if (icolor >= colors.size()) icolor = 0;
        ofSetColor(colors[icolor]);
        ofDrawLine(x, y, x,y-length);
        ofDrawLine(x, y-length, rightBranchX, rightBranchY);
        ofDrawLine(x,y-length, leftBranchX, leftBranchY);

        this->draw(length/2, n-1,rightBranchX,rightBranchY, 30, icolor+1, colors);
        this->draw(length/2,n-1,leftBranchX,leftBranchY, 30, icolor+1, colors);
    }
}