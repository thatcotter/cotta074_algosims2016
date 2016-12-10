//
//  Ship.cpp
//  microCosm
//
//  Created by Andrew Cotter on 11/6/16.
//
//

#include "Ship.hpp"


Ship::Ship(){
    ps.particles.clear();
    pos.x = ofGetWidth()*3/2;
    pos.y = ofGetHeight()*3/2;
    mass = 100.0;
    fuel = 1024;
    thetaInc = 4.0;
    thrustScale = 0.5;
    rocket.addVertex( ofPoint( 0, 10 ) );
    rocket.addVertex( ofPoint( -5, -15 ) );
    rocket.addVertex( ofPoint( 5, -15 ) );
    boostSound.load( "318688__limitsnap-creations__rocket-thrust-effect.wav" );
    boostSound.setVolume( boostSound.getVolume()*1.75 );
    boostSound.play();
    boostSound.setLoop( true );
}

void Ship::setup( ofVec2f _pos ){
    
    pos = _pos;
    theta = 180;
    
}

void Ship::draw(){
    
    ofSetColor(255, 255, 255);
    trail.draw();
    
    ofPushMatrix();
    ofTranslate(pos);
    ofRotate(theta);
    
    ofSetColor(255);
    rocket.draw();
    
//    ofSetColor(255, 0, 0);
    ofDrawEllipse( 0, 0, 20, 20 );
    
//    ofSetColor(0, 255, 0);
    ofDrawRectangle( -20, -13, 10, 25 );
    
//    ofSetColor(0, 0, 255);
    ofDrawRectangle( 10, -13, 10, 25 );
    
    ofPopMatrix();
}

void Ship::drawFuel(){
    
    ofSetColor(255);
    
    ofNoFill();
    ofSetLineWidth(5);
    ofDrawRectangle(30, 30, 300, 30);
    
    
    ofFill();
    ofSetLineWidth(1);
    ofDrawRectangle(30, 30, ofMap(fuel, 0, 1024, 0, 300), 30);
}

void Ship::updateNewt(vector<Planetoid> planets){
    this->turn();
    this->thrust();
    
    for (int i = 0; i < planets.size(); i++) {
        this->planetGravity(planets[i]);
    }
    
    this->ps.updateNewt(planets);
    
    pos += vel;
    vel *= 0.9999999;
    
    trail.curveTo(this->pos);
    
//    if (boost == false && fuel < 1024) {
//    if (boost == false) {
//        fuel += 0.25;
//    }
}

void Ship::planetGravity(Planetoid planet){
    
    ofPoint forceAtPos = planet.attract(this->pos, this->mass) * 0.005;
    this->applyForce( forceAtPos );
    
    vel += accel;
    accel.set(0);
    
}

void Ship::turn(){
    if(left){
        theta -= thetaInc;
    }
    if (right) {
        theta += thetaInc;
    }
}

void Ship::thrust(){
//    if(boost && fuel > 0){
    if(boost){
        float angle = theta + 90;
        ofVec2f force = ofVec2f(1,0).getRotated(angle);
        force *= 0.5;
        force *= thrustScale;
        this->applyForce(force);
        ps.addParticle( pos , -force*0.25  );
        
//        ps.addParticle( pos + ofVec2f(-10,0), -force*0.25  );
//        ps.addParticle( pos + ofVec2f(10,0), -force*0.25  );
//        fuel -= 1;
        boostSound.setPaused(false);
    }else{
        boostSound.setPaused(true);
    }
}

void Ship::checkEdges(){
    if (pos.x < 0) {
        pos.x = ofGetWidth();
    }
    if (pos.x > ofGetWidth()) {
        pos.x = 0;
    }
    if (pos.y < 0) {
        pos.y = ofGetHeight();
    }
    if (pos.y > ofGetHeight()) {
        pos.y = 0;
    }
}