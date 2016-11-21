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
    field.addCircularForce(pos.x, pos.y, radius, strength/3);
    
}

void VectorPuck::display(){
    
    ofSetColor(255);
    ofSetCircleResolution(30);
    
    ofNoFill();
    ofDrawCircle(pos, radius);
    ofDrawCircle(pos, radius*.75);
    ofDrawCircle(pos, radius*.5);
    ofDrawCircle(pos, radius*.25);
    
    ofFill();
    ofDrawCircle(pos, 20);
    
}