#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofToggleFullscreen();
    ofSetEscapeQuitsApp(false);
    
    ofBackground(56,66,89);
    ofSetFrameRate(60);
    ofEnableAntiAliasing();
    
    start.setup("Voyage", "A spacetime oddyssey", "Press Any Key to Begin");
    selectScreen.setup();
    

    level.setup();
    
    pauseScreen.setup();
    
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
        
        if (!pauseScreen.pause) {
        
            selectScreen.update();
            for (int i = 0; i < selectScreen.selectedLevel.size(); i++) {
                if (selectScreen.selectedLevel[i]) {
                    level.setup();
                    level.levelSetup(i);
                }
            }
            
            
        } else if (pauseScreen.pause){
            pauseScreen.lvlSelect = true;
            pauseScreen.update();
        }
        
            
    }
        
    
        
    for (int i = 0; i < scenes.level.size(); i++) {
        if (scenes.level[i]) {
            
            if (!pauseScreen.pause) {
                
                level.update();
                if (level.youWin.menu) {
                    
                    level.youWin.menu = false;
                    
                    scenes.level[i] = false;
                    
                    level.levelSetup(i);
                    selectScreen.setup();
                    scenes.levelSelect = true;
                    
                }
               
            } else if (pauseScreen.pause){
                pauseScreen.lvlSelect = false;
                pauseScreen.update();
                if (pauseScreen.reset) {
                    
                    pauseScreen.reset = false;
                    pauseScreen.pause = false;
                    pauseScreen.opacity = 0;
                    
                    level.levelSetup(i);
                    
                }
                if (pauseScreen.menu) {
                    
                    pauseScreen.menu = false;
                    pauseScreen.pause = false;
                    
                    scenes.level[i] = false;
                    
                    level.levelSetup(i);
                    selectScreen.setup();
                    scenes.levelSelect = true;
                }
            }
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(56,66,89);

    
    if (scenes.start) {
        
        start.draw();
        
    }
    
    if (scenes.levelSelect) {
        
        selectScreen.draw();
        pauseScreen.drawInstructions();
        selectScreen.fadeDraw();
        
    }
    
    for (int i = 0; i < scenes.level.size(); i++) {
        if (scenes.level[i]) {
            level.draw();
            if(!level.win){
                pauseScreen.lvlDraw(level.fuelUsed, level.elapsedTime);
            }
            level.fadeDraw();
        }
        
    }
    
    if (pauseScreen.pause) {
        
        if (pauseScreen.lvlSelect) {
            
            pauseScreen.lvlSelectDraw();
            
        }else{
            
            pauseScreen.draw();
        
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    cout << "keyPressed = " << key << endl;
    
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
    if (pauseScreen.pause) {
        pauseScreen.keyPressed(key);
    }
    if (key == OF_KEY_ESC) {
        if (!level.win) {
            if (pauseScreen.pause && pauseScreen.delay >= 60) {
                pauseScreen.pause = false;
            } else if(! pauseScreen.pause){
                pauseScreen.setup( );
                pauseScreen.pause = true;
            }
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
    
//    for (int i = 0; i < scenes.level.size(); i++) {
//        if (scenes.level[i]) {
//            level.mouseReleased(x, y, button);
//        }
//    }
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
