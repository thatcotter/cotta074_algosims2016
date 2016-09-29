//
//  Particle.hpp
//  wk05_hw_a2d
//
//  Created by Andrew Cotter on 9/28/16.
//
//

#pragma once

#include "ofMain.h"
#include "ofApp.h"

class Particle{
public:
    Particle(ofPoint _l, ofPoint _dir);
    void update();
    void display();
    bool isDead();
    
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;
    float lifespan;
    float topspeed = .75;
};
