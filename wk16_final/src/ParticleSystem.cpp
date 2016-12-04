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
    
//    this->addParticle(origin, ofPoint(0,0));
    
    for (int i = 0; i < particles.size(); i++) {
        
        particles[i].age += 3;
        if (particles[i].isDead()) {
            this->removeParticle(i);
        }
        particles[i].update(field);
    }
    
}

void ParticleSystem::updateNewt(vector<Planetoid> planets){
    
    for (int i = 0; i < particles.size(); i++) {
        
        particles[i].age+=3;
        if (particles[i].isDead()) {
            this->removeParticle(i);
        }
        for (int j = 0; j < planets.size(); j++) {
            particles[i].updateGrav(planets[j]);
        }
        
    }
}

void ParticleSystem::updateGravity(Planetoid planet){
    
    for (int i = 0; i < particles.size(); i++) {
        
        particles[i].age++;
        if (particles[i].isDead()) {
            this->removeParticle(i);
        }
        particles[i].updateGrav(planet);
    }
}

void ParticleSystem::display(){
    
    for (int i = 0; i < particles.size(); i++) {
        particles[i].draw();
    }
    
}

void ParticleSystem::addParticle( ofPoint start, ofPoint force ){
    Particle p;
    p.pos.x = start.x + ofRandom(-10, 10);
    p.pos.y = start.y + ofRandom(-10, 10);
    p.accel = force;
    particles.push_back(p);
}

void ParticleSystem::removeParticle(int i){
    particles.erase( particles.begin() + i );
}
