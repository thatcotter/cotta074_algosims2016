#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofToggleFullscreen();
    
    
    ofBackground(64);
    ofSetFrameRate(60);
    ofEnableAntiAliasing();
    
    start.setup("Voyage", "A spacetime oddyssey", "Press Any Key to Begin");
//    demoLevel.setup();
    newtLevel1.setup();
    newtLevel2.setup();
    selectScreen.setup();
    
    music.load("Tri-Tachyon_-_01_-_The_Glow.mp3");
    music.play();
    music.setLoop(true);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    std::stringstream strm;
    strm << "fps: " << ofGetFrameRate();
    ofSetWindowTitle(strm.str());
    
    scenes.update(selectScreen);
    
    if (scenes.start) {
        
        start.update();
        
    }
    
    if (scenes.levelSelect) {
        selectScreen.update();
    }
    

    if (scenes.level[0] && !scenes.pause) {
        newtLevel1.update();
    }
    
    if (scenes.level[1] && !scenes.pause) {
        newtLevel2.update();
    }
    
    
    if (scenes.win) {
        
    }
    
    if (scenes.lose) {
        
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
        
    if (scenes.start) {
        
        start.draw();
        
    }
    
    if (scenes.levelSelect) {
        
        selectScreen.draw();
        
    }
    
    
    if (scenes.level[0]) {
        
        newtLevel1.draw();
    }
    
    if (scenes.level[1]) {
        
        newtLevel2.draw();
        
    }
    
    if (scenes.win) {
        
    }
    
    if (scenes.lose) {
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (scenes.levelSelect) {
        selectScreen.keyPressed(key);
    }
    
    if (scenes.level[0]) {
        newtLevel1.keyPressed(key);
    }
    
    if (scenes.level[1]) {
        newtLevel2.keyPressed(key);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (scenes.levelSelect) {
        selectScreen.keyReleased(key);
    }
    
    if (scenes.level[0]) {
        newtLevel1.keyReleased(key);
    }
    
    if (scenes.level[1]) {
        newtLevel2.keyReleased(key);
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    if (scenes.levelSelect) {
        selectScreen.mouseMoved(x, y);
    }
    
    if (scenes.level[0]) {
        newtLevel1.mouseMoved(x, y);
    }
    
    if (scenes.level[1]) {
        newtLevel2.mouseMoved(x, y);
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    if (scenes.levelSelect) {
        selectScreen.mouseDragged(x, y, button);
    }

    if (scenes.level[0]) {
        newtLevel1.mouseDragged(x, y, button);
    }
    
    if (scenes.level[1]) {
        newtLevel2.mouseDragged(x, y, button);
    }
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    if (scenes.levelSelect) {
        selectScreen.mousePressed(x, y, button);
    }
    
    if (scenes.level[0]) {
        newtLevel1.mousePressed(x, y, button);
    }
    
    if (scenes.level[1]) {
        newtLevel2.mousePressed(x, y, button);
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    if (scenes.levelSelect) {
        selectScreen.mouseReleased(x, y, button);
    }

    if (scenes.level[0]) {
        newtLevel1.mouseReleased(x, y, button);
    }
    
    if (scenes.level[1]) {
        newtLevel2.mouseReleased(x, y, button);
    }
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
