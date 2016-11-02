//
//  ParticleSystem.cpp
//  wk09_hw_b
//
//  Created by Andrew Cotter on 11/1/16.
//
//

#include "ParticleSystem.hpp"


ParticleSystem::ParticleSystem(){
    
    origin = ofPoint( ofGetWidth()/8, ofGetHeight()/2 );
    
}

void ParticleSystem::setup(){
    
}

void ParticleSystem::update(FlowField field){
    
    this->addParticle(origin);
    
    for (int i = 0; i < particles.size(); i++) {
        
        particles[i].age++;
        if (particles[i].isDead()) {
            this->removeParticle(i);
        }
        
        ofPoint forceAtPos = field.getForceAtPosition(particles[i].pos) * 0.005;
        particles[i].applyForce( forceAtPos );
        
        particles[i].update();
    }
    
}

void ParticleSystem::display(){
    
    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
    
}

void ParticleSystem::addParticle( ofPoint start ){
    Particle p;
    p.pos.x = start.x + ofRandom(-10, 10);
    p.pos.y = start.y + ofRandom(-10, 10);
    particles.push_back(p);
}

void ParticleSystem::removeParticle(int i){
    particles.erase( particles.begin() + i );
}
