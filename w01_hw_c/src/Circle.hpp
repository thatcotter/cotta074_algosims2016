//
//  rectangle.hpp
//  rectangleInterpolatePowf
//
//  Created by Regina Flores on 9/1/16.
//
//

#pragma once

#include "ofMain.h"

class circle {
    
public:
    circle();
    
    void draw();
    void interpolateByPct(float myPct);
    
    ofPoint pos, posa, posb;
    
    float radius;
    
    float pct;
    float shaper;
    
    
};