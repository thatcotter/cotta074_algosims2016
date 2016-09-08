//
//  rectangle.cpp
//  rectangleInterpolatePowf
//
//  Created by Regina Flores on 9/1/16.
//
//

#include "Circle.hpp"


//constructor
circle::circle(){
    
    shaper = 1.0;
    
    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
    
}


void circle::draw(){
    
    
    ofFill();
    ofDrawEllipse(pos.x, pos.y, radius, radius);
    
}

void circle::interpolateByPct(float myPct){
    
    pct = powf(myPct, shaper);

    
    radius = (1-pct)*posa.x + pct * posb.x;

    
}