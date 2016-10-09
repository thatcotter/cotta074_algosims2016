#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    light.setDiffuseColor(ofFloatColor(1.0,1.0,1.0));
    light.setPosition(ofPoint(0.0,0.0,0.0));
    
    for (int i = 0; i < 20; i++)
    {
        nodes.push_back( new Particle(ofRandom(-400, 400),
                                      ofRandom(-400, 400),
                                      ofRandom(-400, 400)));
    }
    
    for (int i = 0; i < nodes.size(); i++)
    {
        for (int j = 0; j < nodes.size(); j+=5)
        {
            if( i == j )
            {
                continue;
            }
            joins.push_back( new Spring(nodes[i], nodes[j]) );
            
        }
        joins[i]->restLength = ofRandom(100);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < joins.size(); i++)
    {
        if (joins[i]->restLength < 1 || joins[i]->restLength > 100) {
            restAnim *= -1;
        }
        joins[i]->restLength += restAnim;
        joins[i]->update();
        
    }
    
    for (int i = 0; i < nodes.size(); i++)
    {
        nodes[i]->bounceOnBoxWalls(500);
        nodes[i]->update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    cam.begin();
    light.enable();
    ofEnableLighting();
    
    ofNoFill();
    ofDrawBox(1000);
    
    for (int i = 0; i < joins.size(); i++)
    {
        joins[i]->draw();
    }
    
    for (int i = 0; i < nodes.size(); i++)
    {
        nodes[i]->draw();
    }
    
    ofDisableLighting();
    light.disable();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    nodes.clear();
    joins.clear();
    setup();
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
