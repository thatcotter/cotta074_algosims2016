#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    points = 0;
    g = 1.0;
    go = 0;
    opaque = 0;
    pink = ofColor(242, 103, 106);
    yellow = ofColor(251, 224, 135);
    lightMauve = ofColor(173, 41, 89);
    mauve = ofColor(98, 1, 60);
    lightGreen = ofColor(166, 242, 219);
    aqua = ofColor(123, 202, 206);
    blue = ofColor(103, 142, 180);
    darkPurp = ofColor(79, 78, 121);
    diedAfter = -0.5;
    
    planetoids.resize(18);
    for (int i = 0; i < 18; i++) {
        planetoids[i].setup(ofRandom(0.5, 1.5), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(darkPurp);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 45; j++) {
            ofSetColor(lightGreen);
//            ellipseMode(CENTER);
            ofDrawEllipse(ofGetWidth()/45*i-60, ofGetWidth()/50*j-45, 1, 1);
        }
    }

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
