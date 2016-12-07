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
    rocket.addVertex( ofPoint( 0, 20 ) );
    rocket.addVertex( ofPoint( -10, -5 ) );
    rocket.addVertex( ofPoint( 10, -5 ) );
}

void Ship::setup( ofVec2f _pos ){
    
    pos = _pos;
    
}

void Ship::draw(){
    
    ofSetColor(255, 255, 255);
    trail.draw();
    
    ofPushMatrix();
    ofTranslate(pos);
    ofRotate(theta);
    
    ofSetColor(255);
    rocket.draw();
    
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

void Ship::update(FlowField field){
    
    ps.update(field);
    this->turn();
    this->thrust();
    
    if(this->screenWrap){
        this->checkEdges();
    }
    
    ofPoint forceAtPos = field.getForceAtPosition(this->pos) * 0.005;
    this->applyForce( forceAtPos );
    
    vel += accel;
    pos += vel;
    
    vel *= 0.99;
    
    accel.set(0);
    
    if (boost == false && fuel < 1024) {
        fuel += 0.25;
    }
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
    
    if (boost == false && fuel < 1024) {
        fuel += 0.25;
    }
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
    if(boost && fuel > 0){
        float angle = theta + 90;
        ofVec2f force = ofVec2f(1,0).getRotated(angle);
        force *= 0.5;
        force *= thrustScale;
        this->applyForce(force);
        ps.addParticle( pos , -force*0.1  );
        fuel -= 1;
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