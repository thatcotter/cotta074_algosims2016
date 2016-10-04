//
//  Blade.cpp
//  wk05_hw_a
//
//  Created by Andrew Cotter on 10/1/16.
//
//

#include "Blade.hpp"

Blade::Blade(){
    
    ofBackground(0);
    
    numPart = 12;
    numSpri = numPart - 1;
    
    particles[0].bFix = true;
    particles[0].fixedX = ofRandom(ofGetWidth());
    
    for(int i =0; i < numPart; i++){
        
        particles[i].setInit(ofPoint(particles[0].fixedX,
                                     ofRandom(ofGetHeight())));
    }
    
    
    //spring array
    springs[0].set(&particles[0], &particles[1]);
    springs[0].restDist = 40;
    
    springs[1].set(&particles[1], &particles[2]);
    springs[1].restDist = 40;
    
    springs[2].set(&particles[2], &particles[3]);
    springs[2].restDist = 40;
    
    springs[3].set(&particles[3], &particles[4]);
    springs[3].restDist = 40;
    
    springs[4].set(&particles[4], &particles[5]);
    springs[4].restDist = 40;
    
    springs[5].set(&particles[5], &particles[6]);
    springs[5].restDist = 40;
    
    springs[6].set(&particles[6], &particles[7]);
    springs[6].restDist = 40;
    
    springs[7].set(&particles[7], &particles[8]);
    springs[7].restDist = 40;
    
    springs[8].set(&particles[8], &particles[9]);
    springs[8].restDist = 40;
    
    springs[9].set(&particles[9], &particles[10]);
    springs[9].restDist = 40;
    
    springs[10].set(&particles[10], &particles[11]);
    springs[10].restDist = 40;
    
    springs[11].set(&particles[11], &particles[12]);
    springs[11].restDist = 40;
    
}

void Blade::update(){
    particles[0].pos.set(particles[0].fixedX, ofGetHeight()/2);

    for(int i =0; i< 11; i++){
        springs[i].update();
    }

    for(int i = 0; i < 12; i++){
        particles[i].addForce(ofPoint(0,-0.1));
        particles[i].update();
//        particles[i].bounding();
    }
    
}

void Blade::draw(){
    for(int i =0; i< 11; i++){
        springs[i].draw();
    }
    
    for(int i = 0; i < 12; i++){
        
        particles[i].draw();
    }
}
