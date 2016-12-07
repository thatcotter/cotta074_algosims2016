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
    
    background.stars.clear();

    ship.trail.clear();
    ship.vel = ofVec2f(0,0);
    ship.setup(ofVec2f( ofGetWidth()*3/2, ofGetWidth()*3/2) );
    
    youWin.setup();
    paused.setup();
    
    
    //then initialize
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
    
    fuelUsed = 0;
    startTime = ofGetElapsedTimef();
    
    background.setup();
    
}




void NewtonianLevel::levelSetup(int lvl){
    
    cout << "newt: lvl == " << lvl << endl;
    
    currentLevel = lvl;
    
    //reset everything first
    planets.clear();
    
    background.stars.clear();
    
    ship.trail.clear();
    ship.vel = ofVec2f(0,0);
    
    youWin.setup();
    paused.setup();
    
    
    //then initialize
    cam.setup(ship.pos);
    
    ofBackground(64);
    ofSetFrameRate(60);
    
    gui.setup();
    gui.add(gravity.setup("gravity", 187.0, 0.0, 300.0));
    gui.add(radius.setup("radius", 100.0, 0.0, 1000.0));
    gui.add(turning.setup("turning speed", 1.65, 0.0001, 2.0));
    gui.add(thrust.setup("thrust", 5.0, 0.000001, 50.0));
    
    if (lvl == 1) {
        
        ship.setup(ofVec2f( ofGetWidth()/2, ofGetWidth()/2) );
        ship.vel = ofVec2f(0,-2);
        
        goal.setup(ship.pos.x + 100, ship.pos.x + 100);
        
        Planetoid p;
        p.pos = ofVec2f(ship.pos - 100);
        p.radiusSeed = 8;
        p.drag = false;
        planets.push_back(p);
        
        
    } else if (lvl == 2) {
        
        ship.setup(ofVec2f( ofGetWidth()/2, ofGetWidth()/2) );
        ship.vel = ofVec2f(-0.25,-1);
        
        goal.setup(ship.pos.x + 100, ship.pos.x + 100);
        
        Planetoid p;
        p.pos = ofVec2f(ship.pos - 150);
        p.radiusSeed = 7;
        p.drag = false;
        planets.push_back(p);
        
        p.pos = ofVec2f(ship.pos.x + 150, ship.pos.y - 150);
        p.radiusSeed = 7;
        p.drag = false;
        planets.push_back(p);
        
        
    } else if (lvl == 3) {
        
        ship.setup(ofVec2f( ofGetWidth()/2, ofGetWidth()/2) );
        ship.vel = ofVec2f(-0.25,-2);
        
        goal.setup(ship.pos.x + 100, ship.pos.x - 100);
        
        Planetoid p;
        p.pos = ofVec2f(ship.pos - 100);
        p.radiusSeed = 7;
        p.drag = false;
        planets.push_back(p);
        
        p.pos = ofVec2f(ship.pos.x + 100, ship.pos.y - 100);
        p.radiusSeed = 7;
        p.drag = false;
        planets.push_back(p);
        
        
    } else if (lvl == 4) {
        
        ship.setup(ofVec2f( ofGetWidth()/2, ofGetWidth()/2) );
        ship.vel = ofVec2f(-0.25,-2);
        
        goal.setup(ship.pos.x + 100, ship.pos.y + 100);
        
        Planetoid p;
        p.pos = ofVec2f(ship.pos - 100);
        p.radiusSeed = 8;
        p.drag = false;
        planets.push_back(p);
        
        p.pos = ofVec2f(ship.pos.x + 100, ship.pos.y - 100);
        p.radiusSeed = 8;
        p.drag = false;
        planets.push_back(p);
        
        
    }
    
    
    debug = false;
    win = false;
    
    fuelUsed = 0;
    startTime = ofGetElapsedTimef();
    
    background.setup();
}

//--------------------------------------------------------------
void NewtonianLevel::update(){
    
    std::stringstream strm;
    strm << "fps: " << ofGetFrameRate();
    ofSetWindowTitle(strm.str());
    
    if (!paused.pause) {
        
    
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
                youWin.reset = false;
                this->levelSetup(currentLevel);
            }
        }
        
        
    }else{
        paused.update();
        if (paused.reset) {
            paused.reset = false;
            this->levelSetup(currentLevel);
        }
    }
    
    if (!win) {
        if (ship.boost) {
            fuelUsed++;
        }
        elapsedTime = ofGetElapsedTimef() - startTime;
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
    
    if (!win) {
        goal.draw();
        goal.drawHint(ship.pos);
    }
    
    ship.ps.display();
    ship.draw();
    
    
    
    cam.end();
    
    
    //UI
    ship.drawFuel();
    
    if(win){
        youWin.draw( to_string(fuelUsed/3), to_string(elapsedTime) );
    }
    
    if(paused.pause){
        paused.draw();
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
    if (paused.pause) {
        paused.keyPressed(key);
    }
    if (key == 'p' || key == 'P') {
        if (!win) {
            paused.setup();
            paused.pause = true;
        }
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