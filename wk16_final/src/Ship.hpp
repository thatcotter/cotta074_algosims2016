//
//  Ship.hpp
//  microCosm
//
//  Created by Andrew Cotter on 11/6/16.
//
//

#ifndef Ship_hpp
#define Ship_hpp
//#include "Particle.h"
#include "ParticleSystem.hpp"
#include <stdio.h>

class Ship : public Particle{
public:
    Ship();
    virtual void draw();
    void drawFuel();
    virtual void update(FlowField field);
    void turn();
    void thrust();
    void checkEdges();
    
    float   theta;
    float   thetaInc;
    bool    left;
    bool    right;
    bool    boost;
    
    float   fuel;
    
    ofMesh rocket;
    ParticleSystem ps;
};
#endif /* Ship_hpp */
