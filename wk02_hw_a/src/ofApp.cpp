#include "ofApp.h"


void ofApp::toroid( int numc, int numt)

{
    int i, j, k;
    double s, t, x, y, z, twopi;
    
    twopi = 2 * PI;
    for (i = 0; i < numc; i++) {
        glBegin(GL_QUAD_STRIP);
        for (j = 0; j <= numt; j++) {
            for (k = 1; k >= 0; k--) {
                s = (i + k) % numc + 0.5;
                t = j % numt;
                //cout << " point:"<< s<< " ";
                //cout << " point:"<< t<< " ";
                x = (1+.1*cos(s*twopi/numc))*cos(t*twopi/numt);
                y = (1+.1*cos(s*twopi/numc))*sin(t*twopi/numt);
                z = .1 * sin(s * twopi / numc);
                //cout << " vertex x:"<< x<< " ";
                glVertex3f(x, y, z);
                
            }  
        }  
        glEnd();  
    }  
    
}



//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(true);
    ofEnableSmoothing();
    
    flowField.setup(24);
    vehicles.resize(1200);
    for (unsigned int i = 0; i < vehicles.size(); i++){
        vehicles[i].setup();
        vehicles[i].setLocation(ofRandomWidth(), ofRandomHeight());
        vehicles[i].setMaxSpeed(ofRandom(2, 5));
        vehicles[i].setMaxForce(ofRandom(0.1, 0.5));
    }
    
    sphere.set(250, 40);
    earth.set(125, 20);
    
    fbo.allocate( ofGetWidth(), ofGetHeight(), GL_RGBA );
    
    float w = fbo.getWidth();
    float h = fbo.getHeight();
    sphere.mapTexCoords(0, h, w, 0);
    sphere.rotate(180, 0, 1, 0);
    
    earth.rotate(180, 0, 1, 0);
    
    emf.load("main_emfisis_chorus_1.mp3");
    emf.play();
    emf.setLoop(true);
    
    titleAlpha = 255;
    myfont.load("break regular.ttf", 60);
    
    ofEnableAlphaBlending();
    
//    torus.loadModel("torus.3DS");
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (unsigned int i = 0; i < vehicles.size(); i++){
        vehicles[i].follow(flowField);
        vehicles[i].update();
        vehicles[i].borders();
    }
    
    flowField.update();
    if (titleAlpha > 0) {
        
        titleAlpha -= 0.5;
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofEnableAlphaBlending();
    ofBackground(15, 15, 15, 5);
    
    
    fbo.begin();
    
    ofEnableAlphaBlending();
    
    ofBackground(0, 0, 0, 0);
    
    if (isDebugMode){
        flowField.display();
    }
    for (unsigned int i = 0; i < vehicles.size(); i++){
        vehicles[i].draw();
    }
    
    ofDisableAlphaBlending();
    
    fbo.end();
    
    cam.begin();
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    draw3D();
//    glDisable(GL_BLEND);
    cam.end();
    
    if (titleAlpha > 0) {
        ofSetColor(0, 0, 0, titleAlpha);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        
        ofSetColor(255, 255, 255);
        ofDrawBitmapString("Sound sample courtesy of NASA", 0, 0);
        myfont.drawString("Sound sample courtesy of NASA", 0, ofGetHeight()/2);
    }
}

void ofApp::draw3D() {
    
    
    
    light.setPosition(ofGetWidth()/2, ofGetHeight()/2, 600);
    light.enable();
    ofDisableAlphaBlending();
    material.begin();
    ofFloatColor earthCol = ofFloatColor( 0.01, 0.1, 1.0, 1.0);
    material.setDiffuseColor(earthCol);
    ofEnableDepthTest();
    earth.draw();
    material.end();
    ofEnableAlphaBlending();
    
//    ofSetColor(255, 50, 255);
    ofFloatColor emfCol = ofFloatColor( 0.9, 0.1, 1.0, 1.0);
    emfMat.begin();
    emfMat.setDiffuseColor(emfCol);
    
    fbo.getTextureReference().bind();
    sphere.draw();
    emfMat.end();
    fbo.getTextureReference().unbind();

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' ') {
        isDebugMode = !isDebugMode;
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
