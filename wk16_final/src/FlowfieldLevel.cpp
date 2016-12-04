//
//  FlowfieldLevel.cpp
//  voyage
//
//  Created by Andrew Cotter on 11/25/16.
//
//

#include "FlowfieldLevel.hpp"

//--------------------------------------------------------------
void FlowfieldLevel::setup(){
    //    ofToggleFullscreen();
    
    cam.setup(ship.pos);
    
    ofBackground(64);
    ofSetFrameRate(60);
    
    gui.setup();
    gui.add(gravity.setup("gravity", 0.6, 0.0, 3.0));
    gui.add(radius.setup("radius", 400.0, 0.0, 1000.0));
    gui.add(turning.setup("turning speed", 3.6, 0.01, 8.0));
    
    fbo1.clear();
    fbo2.clear();
    
    fbo1.allocate( ofGetWidth()*3, ofGetHeight()*3 );
    fbo2.allocate( ofGetWidth()*3, ofGetHeight()*3 );
    
    field.setup( ofGetWidth()*3, ofGetHeight()*3, 24 );
    
    
    for (int i = 0; i < 12; i++) {
        VectorPuck vp;
        vp.pos = ofPoint(ofRandom(ofGetWidth()*3),ofRandom(ofGetHeight()*3));
        vp.drag = false;
        pucks.push_back(vp);
    }
    
    debug = false;
    
}

//--------------------------------------------------------------
void FlowfieldLevel::update(){
    
    std::stringstream strm;
    strm << "fps: " << ofGetFrameRate();
    ofSetWindowTitle(strm.str());
    
    

            
    for (int i = 0; i < pucks.size(); i++) {
        pucks[i].strength = gravity;
        pucks[i].radius = radius;
        
        //        if (ofGetFrameNum()%60 == 0) {
        //            cout << "cam min = " << cam.getMinBounds() << endl;
        //            cout << "cam max = " << cam.getMaxBounds() << endl;
        //        }
        
        if (cam.isInView(pucks[i].pos, pucks[i].radius)) {
            
            pucks[i].update(field);
            //            cout << "updated puck " << i << endl;
            
        }
    }
    
    ship.thetaInc = turning;
    ship.update(field);
    
    ship.turn();
    field.update();
    
    cam.update(ship.pos);
    
    fbo1.begin();
    ofClear(0,0,0,20);
    ship.ps.display();
    fbo1.end();

}

//--------------------------------------------------------------
void FlowfieldLevel::draw(){
    
    
    cam.begin();
    
    fbo2.begin();
    fbo1.draw(0,0);
    fbo2.end();
    fbo2.draw(0,0);
    
    
    if (debug) {
        field.draw(cam);
    }
    
    for (int i = 0; i < pucks.size(); i++) {
        if (cam.isInView(pucks[i].pos, pucks[i].radius)) {
            pucks[i].display();
        }
    }
    
    ship.draw();
    
    cam.end();
    
    ship.drawFuel();
    
    if (debug) {
        gui.draw();
    }
    
}

//--------------------------------------------------------------
void FlowfieldLevel::keyPressed(int key){
    
    if(key == OF_KEY_TAB){
        debug = !debug;
        cam.switchDebug();
    }
    if(key == OF_KEY_LEFT){
        ship.left = true;
    }
    if(key == OF_KEY_RIGHT){
        ship.right = true;
    }
    if(key == 13 || key == 32){
        ship.boost = true;
    }
    
}

//--------------------------------------------------------------
void FlowfieldLevel::keyReleased(int key){
    if(key == OF_KEY_LEFT){
        ship.left = false;
    }
    if(key == OF_KEY_RIGHT){
        ship.right = false;
    }
    if(key == 13 || key == 32){
        ship.boost = false;
    }
}

//--------------------------------------------------------------
void FlowfieldLevel::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void FlowfieldLevel::mouseDragged(int x, int y, int button){
    for (int i = 0; i < pucks.size(); i++) {
        if (pucks[i].drag) {
            pucks[i].pos = ofPoint(x,y) - cam.getOrigin();
        }
    }
}

//--------------------------------------------------------------
void FlowfieldLevel::mousePressed(int x, int y, int button){
    
    for (int i = 0; i < pucks.size(); i++) {
        if (x > pucks[i].pos.x-20+cam.getOrigin().x && x < pucks[i].pos.x+20+cam.getOrigin().x) {
            if (y > pucks[i].pos.y-20+cam.getOrigin().y && y < pucks[i].pos.y+20+cam.getOrigin().y) {
                pucks[i].drag = true;
            }
        }
    }
    
}

//--------------------------------------------------------------
void FlowfieldLevel::mouseReleased(int x, int y, int button){
    
    for (int i = 0; i < pucks.size(); i++) {
        pucks[i].drag = false;
    }
    
}

//--------------------------------------------------------------
void FlowfieldLevel::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void FlowfieldLevel::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void FlowfieldLevel::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void FlowfieldLevel::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void FlowfieldLevel::dragEvent(ofDragInfo dragInfo){ 
    
}