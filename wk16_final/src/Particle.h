//
//  Particle.h
//  VectorField
//
//  Created by Charlie Whitney on 10/7/13.
//
//

#pragma once

#include "ofMain.h"
#include "Planetoid.hpp"

class Particle {
  public:
    Particle();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f accel;
    float mass;
    float age;
    
    void applyForce( ofVec2f force );
    void updateGrav( Planetoid planet );
    void draw();
    bool isDead();
    ofColor hue;
};