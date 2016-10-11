#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    gui.add(rad.setup("path radius", 20, 0, 100));
    gui.add(amp.setup("amplitude", 20, 0, 300));
    
    ofBackground(255);
    ofEnableSmoothing();
    
    ofPoint initPos(0, ofGetHeight()/2);
    for (int i = 0; i < 50; i++) {
        vehicle temp;
        temp.setup(initPos, ofRandom(10), ofRandom(1));
        cars.push_back(temp);
    }
    newPath();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    p.radius = rad;
    p.amplitude = amp;
    p.update();
    
    for (int i = 0; i < cars.size(); i++) {
        cars[i].follow(p);
        cars[i].update();
        cars[i].borders();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    p.draw();
    
    for (int i = 0; i < cars.size(); i++) {
        cars[i].draw();
    }
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::newPath(){
    p.setup();
    p.addPoint(0, ofGetHeight()/2);
    p.addPoint(ofRandom(0, ofGetWidth()/2), ofRandom(0, ofGetHeight()));
    p.addPoint(ofRandom(ofGetWidth()/2, ofGetWidth()), ofRandom(0, ofGetHeight()));
    p.addPoint(ofGetWidth(), ofGetHeight()/2);
}
//--------------------------------------------------------------

void ofApp::keyPressed(int key){
    
    if(key == ' '){
        for (int i = 0; i < cars.size(); i++) {
            cars[i].debug = !cars[i].debug;
        }
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
