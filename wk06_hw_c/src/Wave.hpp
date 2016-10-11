//
//  Wave.hpp
//  wk06_hw_c
//
//  Created by Andrew Cotter on 10/10/16.
//
//

#ifndef Wave_hpp
#define Wave_hpp

#include <stdio.h>
#include "ofMain.h"

class Wave{
    
public:
    Wave();
    void update();
    void draw();
    
    
private:
    float theta; //where are we in the loop
    float xSpace; //space out the dots
    float dx;
    float amplitude;  // Height of wave
    float period;
    vector<float> yVals; //y pos of dots
    
    int a; //alpha value
    int aInc;
    int aa;
    int w; //width of entire wave

};
#endif /* Wave_hpp */
