#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableSmoothing();
    ofSetVerticalSync(TRUE);
    ofBackground(255);
    
    
    //initialize the array:
    
    for(int i = 0; i < 10; i++){
        
        vector<circle> myNewRow;
        
        for (int j = 0; j < 10; j++) {
        
            circle tempCir;
            
            tempCir.pos.x = i * (ofGetWidth()/10) + 20;
            tempCir.pos.y = j * (ofGetHeight()/10) + 10;
            
//            cout << tempCir.pos.x << endl;
            
            tempCir.posa.x = 0;
            tempCir.posb.x = 45;
            
            tempCir.shaper = 0.4 + 0.2 * i;
            tempCir.interpolateByPct(0); //initialize to 0
            
            myNewRow.push_back(tempCir);
            
        }
        
        myCircles.push_back(myNewRow);
        
    }
    
//    cout << myCircles.size() << endl;
    
    pct = 0;
    step = 0.01;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    pct += step;
    
    if(pct > 1 || pct < 0){
        step *= -1;
    }
    
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
        
            myCircles[i][j].interpolateByPct(pct);
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i = 0; i<10; i++){
        
        for(int j = 0; j<10; j++){
            ofSetColor(255, i*20, j*20);
            myCircles[i][j].draw();
        }
        
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
