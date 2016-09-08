#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(TRUE);
    ofBackground(0);
    
    //initialize the array:
    
    for (int i = 0; i < 10; i++) {
        
        rectangle temp;
        myRectangles.push_back(temp);
        
        myRectangles[i].posa.x = ofGetWidth()/2;
        myRectangles[i].posa.y = ofGetHeight()/2;
        myRectangles[i].posb.x = ofGetWidth();
        myRectangles[i].posb.y = ofGetHeight()/2;
        myRectangles[i].shaper = 0.4 + 0.2 * i;
        myRectangles[i].interpolateByPct(0); //initialize to 0
        
    }
    
    
    pct = 0;
    step = 0.01f;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    pct += step;
    
    if(pct > 1){
        pct = 1;
    }
    
    for (int i = 0; i < 10; i++) {
        myRectangles[i].interpolateByPct(pct);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < 10; i++) {
        ofSetColor(255, i*5, i*20);
        
        myRectangles[i].draw();
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
    
    pct = 0;
    for (int i = 0; i < 10; i++) {
        
        myRectangles[i].posa = myRectangles[i].pos;
        
        if (i == 0) {
            myRectangles[i].posb.x = ofGetMouseX();
            myRectangles[i].posb.y = ofGetMouseY();
        } else{
            myRectangles[i].posb.x = myRectangles[i-1].posb.x;
            myRectangles[i].posb.y = myRectangles[i-1].posb.y;
            cout << i;
        }
        cout << endl;
    }
    
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
