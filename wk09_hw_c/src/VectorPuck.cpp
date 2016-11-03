//
//  VectorPuck.cpp
//  wk09_hw_b
//
//  Created by Andrew Cotter on 11/1/16.
//
//

#include "VectorPuck.hpp"

VectorPuck::VectorPuck(){
    
    pos = ofPoint(ofGetWidth()/2,ofGetHeight()/2,300);
//    force = 0;
    radius = 400;
    strength = 2.0;
    
}

void VectorPuck::setup(){
    
    
    
}

void VectorPuck::update(Flowfield &field){
    
    field.addAttractForce(pos.x, pos.y, pos.z, radius, strength);
    
}

void VectorPuck::display(){
    
    ofSetColor(255);
    ofSetCircleResolution(30);
    
    ofNoFill();
    ofDrawCircle(pos, radius*0.8);
    
    ofFill();
    ofDrawCircle(pos, 20);
    
}