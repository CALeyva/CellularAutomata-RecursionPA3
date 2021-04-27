#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    setLevelColors();
    ofSetFrameRate(10);
    this->fractals[0]->setActivate(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSetBackgroundColor(0,0,0);

    timer = timer + 0.125;

    if(play == true){
        if(timer == 1){
            if(check<=10){
                levels++;
                check++;
            }
            else{
                check = 0;
                play = false;
            }
        }
    }

    if(timer == 1){timer = 0;}
    }

//--------------------------------------------------------------
void ofApp::draw(){
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    ofNoFill();
    if(this->fractals[0]->getActivate()){
        dynamic_cast<CircleFractal*>(this->fractals[0])->draw(ofGetWidth()/2, ofGetHeight()/2, levels, 0, this->colors);
    } if(this->fractals[1]->getActivate()){
        dynamic_cast<TreeFractal*>(this->fractals[1])->draw(200, levels, ofGetWidth()/2, ofGetHeight()-50, 30, 0, this->colors);
    } if(this->fractals[2]->getActivate()) {
        dynamic_cast<SierpinskiFractal*>(this->fractals[1])->draw(ofGetWidth() / 3, 10, ofGetHeight() / 2, levels, 0, colors);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // This method is called automatically when any key is pressed
    switch(key){
        case '1':
            setLevelColors();
            this->fractals[0]->setActivate(!this->fractals[0]->getActivate());
            break;
        case '2':
            setLevelColors();
            this->fractals[1]->setActivate(!this->fractals[1]->getActivate());
            break;
        case '3':
            setLevelColors();
            this->fractals[2]->setActivate(!this->fractals[2]->getActivate());
            break;
        case '4':
            setLevelColors();
            // this->fractals[3]->setActivate(!this->fractals[3]->getActivate());
            break;
        case '=': //Increases fractal depth.
            levels++;
            break;
        case '-': //Decreases fractal depth.
            levels--;
            break;
        case ' ':
            play = !play;
            levels = 0;
            check = 0;
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