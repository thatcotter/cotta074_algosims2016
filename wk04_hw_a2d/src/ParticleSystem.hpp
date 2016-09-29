//
//  ParticleSystem.hpp
//  wk05_hw_a2d
//
//  Created by Andrew Cotter on 9/28/16.
//
//
#pragma once

#include "ofMain.h"
#include "Particle.hpp"

class ParticleSystem{
public:
    ParticleSystem();
    void addParticle(float _x, float _y, ofPoint _force);
    void update();
    void run();
    
    vector<Particle> particles;
};

