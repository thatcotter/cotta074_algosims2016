//
//  Planetoid.hpp
//  voyage
//
//  Created by Andrew Cotter on 11/25/16.
//
//

#ifndef Planetoid_hpp
#define Planetoid_hpp

#include <stdio.h>
#include "ofMain.h"
//#include "Ship.hpp"
//#include "ParticleSystem.hpp"

class Planetoid{
public:
    Planetoid();
    void setup();
    void update();
    void draw();
    void drawGravity(float _size, int _iterations);
    
    ofVec2f attractPlanet( Planetoid _p );
//    ofVec2f attractShip( Ship _s );
    ofVec2f attract( ofVec2f _pos, float _mass );
    
    ofPoint pos;
    ofPoint force;
    float radius;
    float radiusSeed;
    float radiusScale;
    float strength;
    float mass;
    
    bool drag;
    
    bool collision;
};

#endif /* Planetoid_hpp */
