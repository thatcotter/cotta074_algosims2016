#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    for (int i = 0; i < 75; i++)
    {
        Particle temp;
        
        temp.setInit( ofPoint(ofRandom(ofGetWidth()) , ofRandom(ofGetHeight()) ) );
        
        temp.color = ofColor( 248+ofRandom(-15, 15),
                              95+ofRandom(-15, 15),
                              115+ofRandom(-15, 15) );
        
        cars.push_back(temp);
    }
    
    dest = ofPoint( mouseX, mouseY );
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    dest = ofPoint( mouseX, mouseY );
    
    
    for (int i = 0; i < cars.size(); i++)
    {
        cars[i].seek( dest );
        
        float area = 45;
        for (int j = 0; j < cars.size(); j++) {
            if (i == j) {
                continue;
            }
            
            if( cars[i].getPosition().distance( cars[j].getPosition() ) < area ){
                
                cars[i].addRepulsionForce( cars[j].getPosition(), area,  0.025 );
                cars[j].addRepulsionForce( cars[i].getPosition(), area, 0.025 );
                
            }
        }
        
        cars[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground( 40, 60, 99 );
    ofSetColor( 255 );
    ofDrawCircle( dest, 4 );
    
    for (int i = 0; i < cars.size(); i++)
    {
        ofSetColor( cars[i].color );
        cars[i].draw();
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
