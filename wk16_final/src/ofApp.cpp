#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofToggleFullscreen();
    
    
    ofBackground(56,66,89);
    ofSetFrameRate(60);
    ofEnableAntiAliasing();
    
    start.setup("Voyage", "A spacetime oddyssey", "Press Any Key to Begin");
    selectScreen.setup();
    
    level.setup();
    
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
        for (int i = 0; i < selectScreen.selectedLevel.size(); i++) {
            if (selectScreen.selectedLevel[i]) {
                level.setup();
                level.levelSetup(i+1);
            }
        }
    }
    
    for (int i = 0; i < scenes.level.size(); i++) {
        if (scenes.level[i] && !scenes.pause) {
            level.update();
            if (level.youWin.menu || level.paused.menu) {
                
                level.youWin.menu, level.paused.menu = false;
                
                scenes.level[i] = false;
                
                level.setup();
                selectScreen.setup();
                scenes.levelSelect = true;
                
            }
        }
    }
    
    
    
//    if (scenes.level[1] && !scenes.pause) {
//        newtLevel2.update();
//        if (newtLevel2.youWin.menu || newtLevel2.paused.menu) {
////            cout << "App: Return to Menu" << endl;
//            newtLevel2.youWin.menu, newtLevel2.paused.menu = false;
//            scenes.level[1] = false;
//            
//            newtLevel2.setup();
//            selectScreen.setup();
//            scenes.levelSelect = true;
//        }
//    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(56,66,89);

    
    if (scenes.start) {
        
        start.draw();
        
    }
    
    if (scenes.levelSelect) {
        
        selectScreen.draw();
        
    }
    
    for (int i = 0; i < scenes.level.size(); i++) {
        if (scenes.level[i]) {
            level.draw();
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (scenes.start) {
//        scenes.keyPressed(key);
    }
    
    if (scenes.levelSelect) {
        selectScreen.keyPressed(key);
    }
    
    for (int i = 0; i < scenes.level.size(); i++) {
        if (scenes.level[i]) {
            level.keyPressed(key);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (scenes.levelSelect) {
        selectScreen.keyReleased(key);
    }
    
    for (int i = 0; i < scenes.level.size(); i++) {
        if (scenes.level[i]) {
            level.keyReleased(key);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    if (scenes.levelSelect) {
        selectScreen.mouseMoved(x, y);
    }
    
    for (int i = 0; i < scenes.level.size(); i++) {
        if (scenes.level[i]) {
            level.mouseMoved(x, y);
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    if (scenes.levelSelect) {
        selectScreen.mouseDragged(x, y, button);
    }
    
    for (int i = 0; i < scenes.level.size(); i++) {
        if (scenes.level[i]) {
            level.mouseDragged(x, y, button);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    if (scenes.levelSelect) {
        selectScreen.mousePressed(x, y, button);
    }
    
    for (int i = 0; i < scenes.level.size(); i++) {
        if (scenes.level[i]) {
            level.mousePressed(x, y, button);
        }
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    if (scenes.levelSelect) {
        selectScreen.mouseReleased(x, y, button);
    }
    
    for (int i = 0; i < scenes.level.size(); i++) {
        if (scenes.level[i]) {
            level.mouseReleased(x, y, button);
        }
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
