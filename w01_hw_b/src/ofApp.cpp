#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(TRUE);
    ofBackground(0);
    
    //initialize the array:
    
    
    myRectangle.posa.x = 0;
    myRectangle.posa.y = ofGetHeight()/2;
    myRectangle.posb.x = 400;
    myRectangle.posb.y = ofGetHeight()/2;
    myRectangle.shaper = 0.5;
    myRectangle.interpolateByPct(0); //initialize to 0

    
    pct = 0;
    step = 0.01f;

}

//--------------------------------------------------------------
void ofApp::update(){
    pct += step;
    
    if(pct > 1 || pct < 0){
        step *= -1;
    }
    
    myRectangle.interpolateByPct(pct);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 0, 0);
    
    myRectangle.draw();
    

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
    
    myRectangle.resetAB();
    pct = 0;
    step = 0.01f;

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
