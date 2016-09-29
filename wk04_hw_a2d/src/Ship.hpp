//
//  Ship.hpp
//  wk05_hw_a2d
//
//  Created by Andrew Cotter on 9/28/16.
//
//
#pragma once
#include "ofMain.h"
#include "ofApp.h"
#include "ParticleSystem.hpp"

class Ship {
    
public:
    
    Ship();
    void update();
    void applyForces();
    void turn();
    void splode();
    void thrust();
    void display();
    
    
//private:
    
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;
    float mass;
    float fuel = 100;
    ParticleSystem ps;
    float damping = 0.998;
    float topspeed = 4;
    float heading = 0;
    float r =6;
    bool thrusting = false;
    
    
};
