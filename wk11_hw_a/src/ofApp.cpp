#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // listen on the given port
    cout << "listening for osc messages on port " << PORT << "\n";
    receiver.setup(PORT);
    
    current_msg_string = 0;
    mouseX = 0;
    mouseY = 0;
    mouseButtonState = "";
    
    ofBackground(255);
    
    shader.load("","shader.frag");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // hide old messages
    for(int i = 0; i < NUM_MSG_STRINGS; i++){
        if(timers[i] < ofGetElapsedTimef()){
            msg_strings[i] = "";
        }
    }
    
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        r = m.getArgAsFloat(0);
        g = m.getArgAsFloat(1);
        b = m.getArgAsFloat(2);
//        ofMap(r,0,1,0,255);
//        ofMap(g,0,1,0,255);
//        ofMap(b,0,1,0,255);
        
        
    }
//    fbo.begin();
//    ofClear(0);
//    shader.begin();
//    shader.setUniform1f("_r", r);
//    shader.setUniform1f("_g", g);
//    shader.setUniform1f("_b", b);
//    shader.end();
//    fbo.end();
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i = 0; i < NUM_MSG_STRINGS; i++){
        
//        ofSetColor(r*255,g*255,b*255);
//        ofDrawRectangle( ofGetWidth()*0.0, ofGetHeight()*0.0, ofGetWidth(), ofGetHeight() );
        shader.begin();
        shader.setUniform1f("_r", r);
        shader.setUniform1f("_g", g);
        shader.setUniform1f("_b", b);
        ofDrawRectangle( ofGetWidth()*0.0, ofGetHeight()*0.0, ofGetWidth(), ofGetHeight() );
        shader.end();
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
