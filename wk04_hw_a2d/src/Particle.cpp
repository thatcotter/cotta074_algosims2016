//
//  Particle.cpp
//  wk05_hw_a2d
//
//  Created by Andrew Cotter on 9/28/16.
//
//

#include "Particle.hpp"


Particle::Particle(ofPoint _l, ofPoint _dir) {
    acceleration = _dir;
    velocity = ofPoint(ofRandom(-5, 5), ofRandom(-5, 5));
    location = _l;
    lifespan = 255.0;
}

void Particle::update(){
    velocity += acceleration;
    velocity.limit(topspeed);
    location += velocity;
    lifespan -= 3.0;
}

void Particle::display(){
//    noStroke();
    ofFill(pink, this->lifespan);
    ofDrawEllipse(location.x, location.y, 4, 4);
}

bool Particle::isDead(){
    if (this->lifespan < 0.0) {
        return true;
    } else {
        return false;
    }
}