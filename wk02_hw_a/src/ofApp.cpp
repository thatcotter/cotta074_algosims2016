#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(true);
    ofEnableSmoothing();
    flowField.setup(20);
    
    sphere.set(250, 20);
    fbo.allocate( ofGetWidth(), ofGetHeight(), GL_RGB );
    
    float w = fbo.getWidth();
    float h = fbo.getHeight();
    sphere.mapTexCoords(0, h, w, 0);
    sphere.rotate(180, 0, 1, 0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    fbo.begin();
    flowField.display();
    fbo.end();
    
    draw3D();
    
    cam.end();
}

void ofApp::draw3D() {
    
    
    
//    light.setPosition(ofGetWidth()/2, ofGetHeight()/2, 600);
//    light.enable();
    material.begin();
    ofEnableDepthTest();
    ofSetColor( ofColor::white );
//    sphere.drawWireframe();
    fbo.getTextureReference().bind();
    
    sphere.draw();
    
    fbo.getTextureReference().unbind();
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
