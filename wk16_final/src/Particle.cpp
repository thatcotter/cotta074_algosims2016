//
//  Particle.cpp
//  Forces
//
//  Created by Charlie Whitney on 9/30/13.
//
//

#include "Particle.h"

Particle::Particle() {
    mass = 1.0;
    age = 0;
    hue.setHsb(ofRandom(0, 32),192,255);
}

void Particle::applyForce(ofVec2f force){
    accel += (force / mass);
}

void Particle::update(FlowField field){
    
    ofPoint forceAtPos = field.getForceAtPosition(this->pos) * 0.005;
    this->applyForce( forceAtPos );
    
    vel += accel;
    pos += vel;
    
    vel *= 0.97;
    
    accel.set(0);
}

void Particle::draw() {
    ofSetColor(hue);
    ofDrawCircle( pos, 2 );
}

bool Particle::isDead(){
    if(this->age < 25){
        return false;
    }else{
        return true;
    }
}