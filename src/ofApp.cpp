#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    setLevelColors();
}

//--------------------------------------------------------------
void ofApp::update(){
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSetBackgroundColor(0,0,0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    ofNoFill();
    if(mode1){
        drawMode1(ofGetWidth()/2, ofGetHeight()/2, 4, 0);
    } if(mode2){
        drawMode2(200, 10, ofGetWidth()/2, ofGetHeight()-50, 30, 0);
    } if(mode3) {
        drawMode3(ofGetWidth() / 3, 10, ofGetHeight() / 2, 10, 0);
    }
}

void ofApp::drawMode1(int x, int y, int n, unsigned int icolor){
    if(n!=0){
        if (icolor >= colors.size()) icolor = 0;
        ofSetColor(colors[icolor]);
        ofDrawCircle(x, y, ((n/4)*100));
        drawMode1(x+100, y, n-1, icolor++);
        drawMode1(x-100, y, n-1, icolor++);
        drawMode1(x, y+100, n-1, icolor++);
        drawMode1(x, y-100, n-1, icolor++);
    }
}
void ofApp::drawMode2(int length, int n, int x, int y, int d, unsigned int icolor){
    if(n != 0){
        int middleY = y-length;
        int leftBranchX = x -length*cos(PI/180*(rand() % 20 + 15));
        int leftBranchY = middleY -length*sin(PI/180*(rand() % 20 + 15));
        int rightBranchX = x +length*cos(PI/180*(rand() % 20 + 15));
        int rightBranchY = middleY -length*sin(PI/180*(rand() % 20 + 15));

        if (icolor >= colors.size()) icolor = 0;
        ofSetColor(colors[icolor]);
        ofDrawLine(x, y, x,y-length);
        ofDrawLine(x, y-length, rightBranchX, rightBranchY);
        ofDrawLine(x,y-length, leftBranchX, leftBranchY);

        drawMode2(length/2, n-1,rightBranchX,rightBranchY, 30, icolor++);
        drawMode2(length/2,n-1,leftBranchX,leftBranchY, 30, icolor++);
    }
    
}

void ofApp::drawMode3(float x, float y, float size, int n, unsigned int icolor){
    if(n == 0) {
        return;
    }

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    if (icolor >= colors.size()) icolor = 0;
    ofSetColor(colors[icolor]);
    ofDrawTriangle(a, b, c);

    drawMode3(x, y, size / 2, n - 1, icolor++);
    drawMode3((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1, icolor++);
    drawMode3();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // This method is called automatically when any key is pressed
    switch(key){
        case '1':
            setLevelColors();
            mode1 = !mode1;
            break;
        case '2':
            setLevelColors();
            mode2 = !mode2;
            break;
        case '3':
            setLevelColors();
            mode3 = !mode3;
            break;
        case '4':
            setLevelColors();
            mode4 = !mode4;
            break;
        case '=': //Increases fractal depth.
            break;
        case '-': //Decreases fractal depth.
            break;
        case ' ':
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}