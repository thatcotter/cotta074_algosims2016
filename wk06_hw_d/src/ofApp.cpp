#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(42,51,86);
    
    for(int i =0; i < 500; i++){
        
        Particle p;
        particles.push_back(p);
        particles[i].init();
        
    }
    
    light.setup();

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = 0; i < particles.size(); i++){
        
        particles[i].update(particles);
        particles[i].bounding();
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    ofEnableLighting();
    light.enable();
    cam.begin();
    
    ofBackground(42,51,86);
    ofSetColor(243,91,37,200);
    
//    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
//    
//    for(int i = 0; i < particles.size(); i++){
//        particles[i].draw();
//    }
    vector<ofPoint> pts;
    for (int i = 0; i < particles.size(); i++) {
        pts.push_back(particles[i].pos);
    }
    string.addVertices(pts);
    string.draw();
    string.clear();
    
    cam.end();
    light.disable();
    ofDisableLighting();
    ofDisableDepthTest();

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
