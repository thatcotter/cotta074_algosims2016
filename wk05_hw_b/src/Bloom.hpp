//
//  Blade.hpp
//  wk05_hw_a
//
//  Created by Andrew Cotter on 10/1/16.
//
//

#ifndef Bloom_hpp
#define Bloom_hpp

#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include "Spring.hpp"

class Bloom{
    
public:
    Bloom();
    void setup(float _rootX, float _rootY);
    void update();
    void draw();
    bool grow();
    void addBranch( Particle *_p );
    
//private:
    vector<Particle> particles;
    vector<Spring> springs;
    
    float numPart;
    float numSpri;
    ofPoint root;
};

#endif /* Blade_hpp */
