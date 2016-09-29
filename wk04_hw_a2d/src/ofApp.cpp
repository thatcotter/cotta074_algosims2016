#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    points = 0;
    g = 1.0;
    go = 0;
    opaque = 0;
    pink = "#F2676A";
    yellow = "#FBE087";
    lightMauve = "#AD2959";
    mauve = "#62013C";
    lightGreen = "#A6F2DB";
    aqua = "#7BCACE";
    blue = "#678EB4";
    darkPurp = "#4F4E79";
    diedAfter = -0.5;
    
    planetoids.resize(18);
    for (int i = 0; i < planetoids; i++) {
//        planetoids[i].setup();
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(darkPurp);
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
