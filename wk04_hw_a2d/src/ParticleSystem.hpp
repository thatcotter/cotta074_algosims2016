//
//  ParticleSystem.hpp
//  wk05_hw_a2d
//
//  Created by Andrew Cotter on 9/28/16.
//
//

#include "ofMain.h"
#include "Particle.hpp"

class ParticleSystem{
public:
    ParticleSystem();
    void addParticle();
    void update();
    
    vector<Particle> particles;
};
