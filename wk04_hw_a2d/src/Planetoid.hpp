//
//  Planetoid.hpp
//  wk05_hw_a2d
//
//  Created by Andrew Cotter on 9/28/16.
//
//

#pragma once
#include "ofMain.h"
#include "ofApp.h"
#include "Ship.hpp"

class Planetoid{
public:
    Planetoid();
    void setup(float m, float x, float y);
    void update();
    void applyForce(ofPoint _force);
    void checkEdges();
    void display();
    ofPoint attractP(Planetoid _p);
    ofPoint attractS(Ship _s);
    
private:
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;
    
    float mass;
    float damping = 0.99995;
};

