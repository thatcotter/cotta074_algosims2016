#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    wind = ofPoint( windDir, 0.0 );
}

//--------------------------------------------------------------
void ofApp::update(){
    
    windDir = sin(ofGetElapsedTimef()) *3;
    
    wind = ofPoint( windDir, 0.0 );
    
    for (int i = 0; i < 50; i++) {
        grass[i].update();
//        int temp =grass[i].numPart;
        for (int j = 0; j < 12; j++) {
            grass[i].particles[j].addForce(wind);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < 50; i++) {
        grass[i].draw();
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
