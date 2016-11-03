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
    age = 0.0;
    hue.setHsb(ofRandom(255), 200, 200);
//    partSphere.setRadius(5);
}

void Particle::applyForce(ofVec3f force){
    accel += (force / mass);
}

void Particle::update(){
    vel += accel;
    pos += vel;
    
    vel*= 0.97;
    
    accel.set(0);
    
    if (pos.x > 1000) pos.x = 0;
    if (pos.y > 1000) pos.y = 0;
    if (pos.z > 1000) pos.z = 0;
    
    if (pos.x < 0) pos.x = 1000;
    if (pos.y < 0) pos.x = 1000;
    if (pos.z < 0) pos.x = 1000;
    
//    partSphere.setPosition(pos.x, pos.y, pos.y);
}

bool Particle::isDead(){
    if(this->age < 1000){
        return false;
    }else{
        return true;
    }
}

void Particle::draw() {
//    ofSetColor(hue);
//    partSphere.draw();
//    ofDrawCircle( pos, 4 );
//    ofVertex(pos);
    glVertex3fv(&pos.x);
}
