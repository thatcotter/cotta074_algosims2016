//
//  ParticleSystem.cpp
//  wk05_hw_a2d
//
//  Created by Andrew Cotter on 9/28/16.
//
//

#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(){
    
}

void ParticleSystem::addParticle(float _x, float _y, ofPoint _force) {
    particles.push_back( Particle(ofPoint(_x, _y), _force));
}
void ParticleSystem::update(){
    for (int i = particles.size ()-1; i >= 0; i--) {
//        Particle p = particles.get(i);
//        p.run();
//        if (p.isDead()) {
//            particles.remove(i);
//        }
    }
}

