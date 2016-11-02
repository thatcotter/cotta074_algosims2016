#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate( 60 );
    
    fontSmall.load("Fonts/DIN.otf", 8 );
    
    ofxGuiSetFont( "Fonts/DIN.otf", 8 );
    ofxGuiSetDefaultWidth( 300 );
    
    gui.setup( "Particles" );
    
    gui.add( numParticles.set("Num particles",  300,  1,  10000) );
    gui.add( randomOffset.set("Random Offset",	0.1f, 0, 5) );
    
    gui.add( spaceFrequency.set("Space Frequency",   1.0f,  0.0001f,  1.0f) );
    gui.add( timeFrequency.set("Time Frequency",	1.0f,  0.0001f,  2.0f) );
    
    gui.add( noiseMagnitude.set("Noise Magnitude",	1.0f,  0.0001f,  2.0f) );
    
    gui.add( oldVelAmount.set("Old Vel Amount",	0.9f, 0, 1) );
    
    gui.add( maxVel.set("Max Vel",	0.1f, 0, 1) );
    gui.add( maxAge.set("Max Age",	3.0f, 0, 10) );
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if( drawGui )
    {
        gui.draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if( key == OF_KEY_TAB )
    {
        drawGui = !drawGui;
    }
    else if( key == 'f' )
    {
        ofToggleFullscreen();
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
