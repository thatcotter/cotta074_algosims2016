//
//  rectangle.cpp
//  rectangleInterpolatePowf
//
//  Created by Regina Flores on 9/1/16.
//
//

#include "rectangle.hpp"


//constructor
rectangle::rectangle(){
    
    shaper = 1.0;
    
}


void rectangle::draw(){
    
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(pos.x, pos.y, 20, 20);
    
}

void rectangle::interpolateByPct(float myPct){
    
    posb.x = ofGetMouseX();
    posb.y = ofGetMouseY();
    
    pct = powf(myPct, shaper);
    pos.x = (1-pct)*posa.x + pct * posb.x;
    pos.y = (1-pct)*posa.y + pct * posb.y;
    
    pct = ofDist(posa.x, posa.y, pos.x, pos.y) / ofDist(posa.x, posa.y, posb.x, posb.y);
    
}