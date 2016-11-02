//
//  VectorPuck.cpp
//  wk09_hw_b
//
//  Created by Andrew Cotter on 11/1/16.
//
//

#include "VectorPuck.hpp"

VectorPuck::VectorPuck(){
    
    pos = ofPoint(ofGetWidth()/2,ofGetHeight()/2);
//    force = 0;
    radius = 200;
    strength = 2.0;
    
}

void VectorPuck::setup(){
    
    
    
}

void VectorPuck::update(FlowField &field){
    
    field.addAttractForce(pos.x, pos.y, radius, strength);
    
}

void VectorPuck::display(){
    
    ofSetColor(255);
    ofSetCircleResolution(30);
    
    ofNoFill();
    ofDrawCircle(pos, radius);
    
    ofFill();
    ofDrawCircle(pos, 20);
    
}