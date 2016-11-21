//
//  ParticleSystem.hpp
//  wk09_hw_b
//
//  Created by Andrew Cotter on 11/1/16.
//
//

#ifndef ParticleSystem_hpp
#define ParticleSystem_hpp

#include <stdio.h>
#include "Particle.h"
#include "FlowField.h"

class ParticleSystem{
    
public:
    ParticleSystem();
    void setup();
    void update(FlowField field);
    void display();
    
    void addParticle(ofPoint start, ofPoint force);
    void removeParticle(int i);
    
    vector<Particle> particles;
    ofPoint origin;
};

#endif /* ParticleSystem_hpp */
