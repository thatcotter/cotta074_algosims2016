#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    
    ofSetFrameRate( 60 );
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
    
    field.setup(1000, 1000, 1000, 64);
    puck.setup();
    pSysytem.setup();
}
//--------------------------------------------------------------
void ofApp::update(){
    puck.update(field);
    field.update();
    pSysytem.update(field);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    ofPushMatrix();{
        
        ofTranslate(field.width*0.5*-1, field.height*0.5*-1, field.depth*0.5*-1);
        
        if(drawField){
            field.draw();
        }
        
        glBegin(GL_POINTS);
        pSysytem.display();
        glEnd();
        
        puck.display();
        
    } ofPopMatrix();
    
    
    cam.end();
    
    if( drawGui )
    {
//        gui.draw();
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if( key == OF_KEY_TAB )
    {
        drawGui = !drawGui;
        drawField = !drawField;
    }
    else if( key == 'f' )
    {
        ofToggleFullscreen();
    }
    
    if (key == OF_KEY_UP) {
        puck.pos.y+=25;
    }
    if (key == OF_KEY_DOWN) {
        puck.pos.y-=25;
    }
    if (key == OF_KEY_LEFT) {
        puck.pos.x-=25;
    }
    if (key == OF_KEY_RIGHT) {
        puck.pos.x+=25;
    }
    if (key == 'z') {
        puck.pos.z+=25;
    }
    if (key == 'x') {
        puck.pos.z-=25;
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
    if (drag) {
        puck.pos = ofPoint(x,y);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (x > puck.pos.x-20 && x < puck.pos.x+20) {
        if (y > puck.pos.y-20 && y < puck.pos.y+20) {
            drag = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    drag = false;
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
