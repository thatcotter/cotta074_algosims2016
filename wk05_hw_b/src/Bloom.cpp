//
//  Bloom.cpp
//  wk05_hw_a
//
//  Created by Andrew Cotter on 10/1/16.
//
//

#include "Bloom.hpp"

Bloom::Bloom(){
    
}

void Bloom::setup(float _rootX, float _rootY){
    
    partIndex = 0;
    
    root.x = _rootX;
    root.y = _rootY;
    
    Particle temp;
    
    particles.push_back(temp);
    
    particles[0].bFix = true;
    particles[0].fixedX = ofGetWidth();
    
    for (int i = 0; i < 10; i++) {
        if (this->grow()) {
            this->addBranch( &particles[partIndex] );
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


void Bloom::addBranch( Particle * _p ){
    
    Particle tempP; //make a temporary particle
    tempP.setInit( _p->getPosition(), _p->getVelocity()); //set its vectors to that of * _p
    tempP.bFix = false; //it's position isn't fixed
    tempP.pos += ofPoint( ofRandom( -10, 10),
                          ofRandom( -10, 10),
                          ofRandom( -10, 10)); //vary the position a little
    
    Spring tempS; //make a temporary spring
    tempS.set( _p, &tempP); //pass pointers to the particles into the spring
    tempS.restDist = 20; // set the rest distance
    
    
    particles.push_back(tempP); //save the temp particle to the array
    partIndex += 1; //add to the index value
    
    springs.push_back(tempS); //add the temp spring to the array
    
    
    
//    springs[partIndex - 1].set( _p, &particles[partIndex]);
//    springs[partIndex - 1].restDist = 20;
    
//    cout << springs.size() << endl;
    
}
