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
    radius = 200;
    strength = 2.0;
    
}

void VectorPuck::setup(){
    
    
    
}

void VectorPuck::update(FlowField &field){
    
    field.addAttractForce(pos.x, pos.y, radius, strength);
    field.addCircularForce(pos.x, pos.y, radius, strength/4);
    
}

void VectorPuck::display(){
    
    ofSetColor(255);
    ofSetCircleResolution(30);
    
    ofNoFill();
    this->drawGravity(radius, 4);
    
}

void VectorPuck::drawGravity(float _size, int _iterations){
    
    float size = _size;
    int iterations = _iterations;
    
    if (_iterations > 0) {
        ofDrawCircle(pos, size);
        this->drawGravity(size/2, iterations - 1);
    }else{
        ofFill();
        ofDrawCircle(pos, size);
    }
}
