//
//  NewtonianLevel.cpp
//  voyage
//
//  Created by Andrew Cotter on 11/25/16.
//
//

#include "NewtonianLevel.hpp"


//--------------------------------------------------------------
void NewtonianLevel::setup(){
    
    //reset everything first
    planets.clear();
    ship.trail.clear();
    ship.vel = ofVec2f(0,0);
    ship.setup(ofVec2f( ofGetWidth()*3/2, ofGetWidth()*3/2) );
    youWin.reset = false;
    
    cam.setup(ship.pos);
    
    ofBackground(64);
    ofSetFrameRate(60);
    
    gui.setup();
    gui.add(gravity.setup("gravity", 187.0, 0.0, 300.0));
    gui.add(radius.setup("radius", 100.0, 0.0, 1000.0));
    gui.add(turning.setup("turning speed", 1.65, 0.0001, 2.0));
    gui.add(thrust.setup("thrust", 5.0, 0.000001, 50.0));
    
    
    for (int i = 0; i < 120; i++) {
        Planetoid p;
        p.pos = ofPoint(ofRandom(-ofGetWidth()*5, ofGetWidth()*5),
                        ofRandom(-ofGetHeight()*5, ofGetHeight()*5));
        p.drag = false;
        planets.push_back(p);
    }
    
    debug = false;
    win = false;
    
    background.setup();
    youWin.setup();
    
    goal.setup(ship.pos.x + 75, ship.pos.y + 75);//--------
    
}

//--------------------------------------------------------------
void NewtonianLevel::update(){
    
    std::stringstream strm;
    strm << "fps: " << ofGetFrameRate();
    ofSetWindowTitle(strm.str());
    
    
    for (int i = 0; i < planets.size(); i++) {
        planets[i].strength = gravity;
        planets[i].radiusScale = radius;
        planets[i].update();
    }
    
    
    ship.thetaInc = turning;
    ship.thrustScale = thrust;
    ship.turn();
    ship.updateNewt(planets);
    
    
    cam.update(ship.pos);
    
    if(goal.collide(ship.pos)){
        win = true;
    }
    
    if(win){
        youWin.update();
        if (youWin.reset) {
            this->setup();
        }
    }
    
}

//--------------------------------------------------------------
void NewtonianLevel::draw(){
    
    //SCENE
    cam.begin();
    
    background.draw();
    
    for (int i = 0; i < planets.size(); i++) {
        if (cam.isInView(planets[i].pos, planets[i].radius)) {
            planets[i].draw();
        }
    }
    
    goal.draw();
    
    ship.ps.display();
    ship.draw();
    
    goal.drawHint(ship.pos);
    
    cam.end();
    
    
    //UI
    ship.drawFuel();
    
    if(win){
        youWin.draw();
    }
    
    
    if (debug) {
        gui.draw();
    }
    
}

//--------------------------------------------------------------
void NewtonianLevel::keyPressed(int key){
    
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
void NewtonianLevel::keyReleased(int key){
    if(key == OF_KEY_LEFT){
        ship.left = false;
    }
    if(key == OF_KEY_RIGHT){
        ship.right = false;
    }
    if(key == 13 || key == 32){
        ship.boost = false;
    }
    if (win) {
        youWin.keyPressed(key);
    }
}

//--------------------------------------------------------------
void NewtonianLevel::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void NewtonianLevel::mouseDragged(int x, int y, int button){
    for (int i = 0; i < planets.size(); i++) {
        if (planets[i].drag) {
            planets[i].pos = ofPoint(x,y) - cam.getOrigin();
        }
    }
}

//--------------------------------------------------------------
void NewtonianLevel::mousePressed(int x, int y, int button){
    
    for (int i = 0; i < planets.size(); i++) {
        if (x > planets[i].pos.x-20+cam.getOrigin().x && x < planets[i].pos.x+20+cam.getOrigin().x) {
            if (y > planets[i].pos.y-20+cam.getOrigin().y && y < planets[i].pos.y+20+cam.getOrigin().y) {
                planets[i].drag = true;
            }
        }
    }
    
}

//--------------------------------------------------------------
void NewtonianLevel::mouseReleased(int x, int y, int button){
    
    for (int i = 0; i < planets.size(); i++) {
        planets[i].drag = false;
    }
    
}

//--------------------------------------------------------------
void NewtonianLevel::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void NewtonianLevel::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void NewtonianLevel::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void NewtonianLevel::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void NewtonianLevel::dragEvent(ofDragInfo dragInfo){
    
}