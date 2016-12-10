//
//  Ship.hpp
//  microCosm
//
//  Created by Andrew Cotter on 11/6/16.
//
//

#ifndef Ship_hpp
#define Ship_hpp
#include "ParticleSystem.hpp"
#include "Planetoid.hpp"
#include <stdio.h>

class Ship : public Particle{
public:
    Ship();
    void setup( ofVec2f _pos );
    virtual void draw();
    void drawFuel();
    virtual void updateNewt(vector<Planetoid> planets );
    void planetGravity(Planetoid planet);
    void turn();
    void thrust();
    void checkEdges();
    
    float   theta;
    float   thetaInc;
    float   thrustScale;
    
    bool    left;
    bool    right;
    bool    boost;
    
    bool    screenWrap;
    
    float   fuel;
    
    ofMesh      rocket;
    ofPolyline  trail;
    
    ofSoundPlayer  boostSound;
    
    ParticleSystem ps;
};
#endif /* Ship_hpp */
