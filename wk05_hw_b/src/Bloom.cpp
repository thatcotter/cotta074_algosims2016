//
//  Blade.cpp
//  wk05_hw_a
//
//  Created by Andrew Cotter on 10/1/16.
//
//

#include "Bloom.hpp"

Bloom::Bloom(){
    
}

void Bloom::setup(float _rootX, float _rootY){
    
    root.x = _rootX;
    root.y = _rootY;
    
    Particle temp;
    
    particles.push_back(temp);
    
    particles[0].bFix = true;
    particles[0].fixedX = ofGetWidth();
    
    for (int i = 0; i < 4; i++) {
        if (this->grow()) {
            this->addBranch( &particles[0] );
        }
    }
    
}

void Bloom::update(){
    particles[0].pos.set(root);
    
    if (springs.size() > 0 ) {
        for(int i =0; i< springs.size(); i++){
            springs[i].update();
        }
    }
    
    for(int i = 0; i < particles.size(); i++){
        particles[i].addForce(ofPoint(0,-0.1));
        particles[i].update();
    }
    
}

void Bloom::draw(){
    if (springs.size() > 0 ) {
        
        for(int i =0; i< 11; i++){
            springs[i].draw();
        }
        
    }
    
    for(int i = 0; i < 12; i++){
        
        particles[i].draw();
    }
}

bool Bloom::grow(){
    float dice = ofRandom(1);
    if (dice > .5) {
        return true;
    } else{
        return false;
    }
}


void Bloom::addBranch( Particle *_p ){
    
    Particle tempP;
    tempP.setInit( _p->pos, _p->getVelocity());
    
    Spring tempS;
    tempS.set( _p, &tempP);
    tempS.restDist = 20;
    
    particles.push_back(tempP);
    springs.push_back(tempS);
    
    cout << "grow" << endl;
    
}
