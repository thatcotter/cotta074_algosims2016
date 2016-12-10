//
//  LevelSelect.cpp
//  voyage
//
//  Created by Andrew Cotter on 11/28/16.
//
//

#include "LevelSelect.hpp"


LevelSelect::LevelSelect(){
    
    numLevels = 12;
    
}

//--------------------------------------------------------------
void LevelSelect::setup(){
    
    cam.setup(ship.pos);
    
    
    gui.setup();
    gui.add(gravity.setup("gravity", 187.0, 0.0, 300.0));
    gui.add(radius.setup("radius", 100.0, 0.0, 1000.0));
    gui.add(turning.setup("turning speed", 2.65, 0.01, 8.0));
    gui.add(thrust.setup("thrust", 3.6, 0.01, 8.0));
    
    
    planets.clear();
    
    for (int i = 0; i < numLevels; i++) {
        Planetoid p;
        
        p.pos = ofPoint(ofGetWidth()*0.5 + cos( (i-3)*TWO_PI / numLevels) * (ofGetWidth()*0.2),
                        ofGetHeight()*0.5 + sin( (i-3)*TWO_PI / numLevels) * (ofGetWidth()*0.2));

        p.drag = false;
        p.radiusScale = 1.0;
        p.radiusSeed = 1.5;
        planets.push_back(p);
    }
    
    for (int i = 0; i < planets.size(); i++) {
        
        planets[i].strength = gravity;
        planets[i].radiusScale = radius;
        planets[i].update();
        
    }
    
    ofVec2f shipPos( ofGetWidth()/2, ofGetHeight()/2 );
    
    ship.setup(shipPos);
    ship.vel = ofVec2f( 0, 0 );
    ship.trail.clear();
    ship.left, ship.right, ship.boost = false;
    
    selectedLevel.clear();
    selectedLevel.resize(numLevels);
    
    debug = false;
    
    fadeOpacity = 255;
    pct = 0;
    fadePct = 0;
    fadeIn = true;
    fadeOut = false;
    
    
    background.stars.clear();
    background.setup();
    
}


//--------------------------------------------------------------


void LevelSelect::update(){
    
    std::stringstream strm;
    strm << "fps: " << ofGetFrameRate();
    ofSetWindowTitle(strm.str());
    
    
    if ( fadeIn ) {
        
        this->fadeInUpdate();
        cam.update(ship.pos);

        
    } else if ( fadeOut ){
        
        this->fadeOutUpdate();
        
    }else{
    
        for (int i = 0; i < planets.size(); i++) {
            
            planets[i].strength = gravity;
            planets[i].radiusScale = radius;
            planets[i].update();
            
        }
        
        
        
        ship.thetaInc = turning;
        ship.thrustScale = thrust;
        
        ship.updateNewt(planets);
        
        for (int i = 0; i < planets.size(); i++) {
            
            ofVec2f force = planets[i].pos - ship.pos;
            float distance= force.length();
            if ( distance < planets[i].radius/12 ) {
                fadeOut = true;
                selectedLevel[i] = true;
            }
            
        }
        
        cam.update(ship.pos);
        
    }

}

//--------------------------------------------------------------
void LevelSelect::draw(){
    
    
    cam.begin();
    
    background.draw();
    
    
    for (int i = 0; i < planets.size(); i++) {
        if (cam.isInView(planets[i].pos, planets[i].radius)) {
            planets[i].draw();
            string level = "Level " + to_string(i + 1);
            ofDrawBitmapString(level, planets[i].pos.x - 20, planets[i].pos.y - 50);
        }
    }
    
    
    ship.ps.display();
    ship.draw();
    
    
    cam.end();

    if (debug) {
        gui.draw();
    }
    
}

//--------------------------------------------------------------
void LevelSelect::keyPressed(int key){
    
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
void LevelSelect::keyReleased(int key){
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
void LevelSelect::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void LevelSelect::mouseDragged(int x, int y, int button){
    for (int i = 0; i < planets.size(); i++) {
        if (planets[i].drag) {
            planets[i].pos = ofPoint(x,y) - cam.getOrigin();
        }
    }
}

//--------------------------------------------------------------
void LevelSelect::mousePressed(int x, int y, int button){
    
    for (int i = 0; i < planets.size(); i++) {
        if (x > planets[i].pos.x-20+cam.getOrigin().x && x < planets[i].pos.x+20+cam.getOrigin().x) {
            if (y > planets[i].pos.y-20+cam.getOrigin().y && y < planets[i].pos.y+20+cam.getOrigin().y) {
                planets[i].drag = true;
            }
        }
    }
    
}

//--------------------------------------------------------------
void LevelSelect::mouseReleased(int x, int y, int button){
    
    for (int i = 0; i < planets.size(); i++) {
        planets[i].drag = false;
    }
    
}

//--------------------------------------------------------------
void LevelSelect::fadeInUpdate(){
    
    this->pct += 0.01;
    
    this->fadeInterpolate(pct);
    
    if (fadeOpacity <= 0) {
        fadeIn = false;
    }
    
}

void LevelSelect::fadeOutUpdate(){
    
    this->pct -= 0.01;
    
    this->fadeOpacity++;
    
    if (fadeOpacity > 255) {
        fadeOut = false;
    }
}

void LevelSelect::fadeInterpolate(float _pct){
    
    fadePct = pow(_pct, 0.8);
    fadeOpacity = (1-fadePct) * 255;
    
}

void LevelSelect::fadeDraw(){
    
    ofSetColor(0, 0, 0, fadeOpacity);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
}

bool LevelSelect::anyLvlPicked(){
    
    int temp;
    
    for (int i = 0; i < selectedLevel.size(); i++) {
        if (selectedLevel[i] == true) {
            cout << " a level was selected " << endl;
            return true;
            break;
        }
    }
    
    return false;
    
}

//--------------------------------------------------------------
void LevelSelect::drawControls(){
    
    ofDrawBitmapString("Controls", 50, 50 );
    ofDrawBitmapString("Turn: Left & Right", 50, 75 );
    ofDrawBitmapString("Boost: Space or A Button", 50, 100 );
    ofDrawBitmapString("Pause: Esc Key or START Button", 50, 125 );
    
}