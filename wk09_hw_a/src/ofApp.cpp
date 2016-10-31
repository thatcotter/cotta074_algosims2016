#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
   
    gui.setup();
    gui.add(res.setup("resolution", 6, 6, 30));
    gui.add(speed.setup("speed", 0.01, 0.0, 0.05));
    gui.add(bug.setup("debug", false));
    
    water.setup(ofGetWidth(), ofGetHeight(), res);
    water.setPerlin();
    debug = bug;
    ofBackground(10, 30, 70);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (water.resolution != res) {
        water.setup(ofGetWidth(), ofGetHeight(), res);
    }
    water.zOffSpeed = speed;
    water.update();
    debug = bug;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    if (!debug) {
        ofEnableAlphaBlending();
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        water.drawRipple();
        ofDisableBlendMode();
    }
   
    
    if (debug) {
        ofSetColor(220);
        water.draw();
    }
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
//    if( key == 'd'){
//        debug = !debug;
//    }

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
