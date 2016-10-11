//
//  path.hpp
//  wk06_hw_b
//
//  Created by Andrew Cotter on 10/11/16.
//
//

#ifndef path_hpp
#define path_hpp

#include <stdio.h>
#include "ofMain.h"

class path{
    
public:
    path();
    void setup();
    void addPoint(float x, float y);
    void update();
    void draw();
    
    
    vector<ofPoint> points;
    float radius;
    
    
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

#endif /* path_hpp */
