
//inspired by Cipher Prime's Auditorium
//http://www.cipherprime.com/games/auditorium/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(64);
    ofSetFrameRate(60);
    
    fbo1.allocate( ofGetWidth(), ofGetHeight() );
    fbo2.allocate( ofGetWidth(), ofGetHeight() );
    
    field.setup( ofGetWidth(), ofGetHeight(), 24 );
    system.setup();
    puck.setup();
    drag = false;
    debug = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    std::stringstream strm;
    strm << "fps: " << ofGetFrameRate();
    ofSetWindowTitle(strm.str());
    
    puck.update(field);
    system.update(field);
    field.update();
    
    fbo1.begin();
    ofClear(0,0,0,20);
    system.display();
    fbo1.end();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (debug) {
        field.draw();
    }
    
    fbo2.begin();
    fbo1.draw(0,0);
    fbo2.end();
    fbo2.draw(0,0);
    
    puck.display();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == OF_KEY_TAB){
        debug = !debug;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if (drag) {
        puck.pos = ofPoint(x,y);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    if (x > puck.pos.x-20 && x < puck.pos.x+20) {
        if (y > puck.pos.y-20 && y < puck.pos.y+20) {
            drag = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    drag = false;
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
