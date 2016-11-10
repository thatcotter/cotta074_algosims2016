#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    sphere.set(250, 240);
    
    vidGrabber.setVerbose(true);
    vidGrabber.setup(320,240);
    
//    sphereImage.loadImage("images/infinity.jpg");
//    sphereTexture = sphereImage.getTextureReference();
//    sphereTexture.readToPixels(pixels);
    
    float w = sphereTexture.getWidth();
    float h = sphereTexture.getHeight();
    sphere.mapTexCoords(0, h, w, 0);
    extrusionRange.set("Extrusion Range", 1.0f, 0, 1.25f);
    
    deformSpeed.set("Displace Speed", 1.0f, 0, 2.0f);
    
    drawGui.set("Draw GUI", true, false, true);
    rotate.set("Rotate Cam", false, false, true);
    doDeform.set("Enable Displace", false, false, true);
    
    gui.setup();
    gui.add(drawGui);
    gui.add(rotate);
    gui.add(doDeform);
    gui.add(deformSpeed);
    gui.add(extrusionRange);
    
    origVertices = sphere.getMesh().getVertices();

}

//--------------------------------------------------------------
void ofApp::update(){
    
    vidGrabber.update();
    
    sphereTexture = vidGrabber.getTexture();
    sphereTexture.readToPixels(pixels);
    
    float w = sphereTexture.getWidth();
    float h = sphereTexture.getHeight();
    sphere.mapTexCoords(0, h, w, 0);
    
    if (doDeform) deformVerts();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    draw3d();
    
    if (drawGui) gui.draw();
    
}

void ofApp::draw3d() {
    sphereTexture.bind();
    light.setPosition(ofGetWidth()/2, ofGetHeight()/2, 1200);
    light.enable();
    material.begin();
    ofEnableDepthTest();
    
    cam.begin();
    ofSetColor(ofColor::white);
    
    if (rotate) {
        float time = ofGetElapsedTimef();
        float longitude = 10 * time;
        float latitude = 10 * sin(time * 0.8f);
        float radius = 600.0f + 500.0f * sin(time * 0.4f);
        cam.orbit(longitude, latitude, radius, ofPoint(0, 0, 0));
    }
    
    sphere.draw();
    cam.end();
    
    ofDisableDepthTest();
    material.end();
    light.disable();
    ofDisableLighting();
    sphereTexture.unbind();
}

void ofApp::deformVerts() {
    //vector<ofPoint> vertices = origVertices;
    vector<ofPoint> &sphereVerts = sphere.getMesh().getVertices();
    vector<ofFloatColor> &sphereColors = sphere.getMesh().getColors();
    
    float extrusionAmount = sin(ofGetElapsedTimef() * deformSpeed) * extrusionRange;
    
    //grab a new frame
//    vidGrabber.update();
    
    //update the mesh if we have a new frame
    if (vidGrabber.isFrameNew()){
        //this determines how far we extrude the mesh
        for (int i=0; i<vidGrabber.getWidth()*vidGrabber.getHeight(); i++){
            
            ofFloatColor sampleColor(vidGrabber.getPixels()[i*3]/255.f,     // r
                                     vidGrabber.getPixels()[i*3+1]/255.f,	// g
                                     vidGrabber.getPixels()[i*3+2]/255.f);	// b
            
            //now we get the vertex aat this position
            //we extrude the mesh based on it's brightness
            if (i < sphereVerts.size()) {
            
                ofVec2f tmpVec = sphere.getMesh().getTexCoords()[i];
                tmpVec.x = ofClamp( tmpVec.x, 0, pixels.getWidth()-1 );
                tmpVec.y = ofClamp( tmpVec.y, 0, pixels.getHeight()-1 );
                
                float br = pixels.getColor(tmpVec.x, tmpVec.y).getBrightness();
//                mainMesh.setVertex(i, tmpVec);
//                mainMesh.setColor(i, sampleColor);
                
                sphereVerts[i] = origVertices[i] * (1 + br / 255.0 * extrusionAmount);
                if (i < sphereColors.size()) {
                    sphereColors[i].set(sampleColor);
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case 'G':
            drawGui = !drawGui;
            break;
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
