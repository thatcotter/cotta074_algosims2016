//
//  Planetoid.cpp
//  voyage
//
//  Created by Andrew Cotter on 11/25/16.
//
//

#include "Planetoid.hpp"

Planetoid::Planetoid(){
    
    pos = ofPoint( ofGetWidth()/2, ofGetHeight()/2 );
    radiusSeed = ofRandom(10);
    radiusScale = 100;
    radius = radiusSeed * radiusScale;
    strength = 2.0;
    mass = radius;
    collision = false;

}

void Planetoid::setup(){
    
}

void Planetoid::update(){
    
    radius = radiusSeed * radiusScale;
    mass = radius;
    
}

void Planetoid::draw(){
    
    ofSetColor(255);
    ofSetCircleResolution(30);
    
    
    this->drawGravity(radius, 4);
    
}

void Planetoid::drawGravity(float _size, int _iterations){
    
    float size = _size;
    int iterations = _iterations;
    
    if (_iterations > 0) {
        ofNoFill();
        ofSetColor(255, 255, 255, 255/iterations);
        ofDrawCircle(pos, size);
        this->drawGravity(size/2, iterations - 1);
    }else{
        ofFill();
        ofDrawCircle(pos, size);
    }
    
}


ofVec2f Planetoid::attract( ofVec2f _pos, float _mass ){
    
    ofVec2f force = this->pos - _pos;
    float distance= force.length();
    
    
    if (distance < (this->radius/6)) {
        collision = true;
    }
    
    distance = ofClamp(distance, 25.0, 5000.0);
    force.normalize();
    
    float magnitude = (this->strength * mass * _mass) / ( distance * distance );
    force *= magnitude;
    return force;
    
}