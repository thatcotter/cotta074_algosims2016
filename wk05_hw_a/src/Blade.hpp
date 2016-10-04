//
//  Blade.hpp
//  wk05_hw_a
//
//  Created by Andrew Cotter on 10/1/16.
//
//

#ifndef Blade_hpp
#define Blade_hpp

#include "ofMain.h"
#include "Particle.hpp"
#include "Spring.hpp"

class Blade{
    
public:
    Blade();
    void update();
    void draw();
    
//private:
    Particle particles[12];
    Spring springs[11];
    
    float numPart;
    float numSpri;
};

#endif /* Blade_hpp */
