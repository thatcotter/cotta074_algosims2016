//
//  Planetoid.cpp
//  wk05_hw_a2d
//
//  Created by Andrew Cotter on 9/28/16.
//
//

#include "Planetoid.hpp"

//Planetoid(){
//    
//}

void Planetoid::setup(float _m, float _x, float _y){
    mass = _m;
    location = ofPoint(_x, _y);
    velocity = ofPoint(0, 0);
    acceleration = ofPoint(ofRandom(-0.25, 0.25),
                           ofRandom(-0.25, 0.25));
};

void Planetoid::update(){
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
};

void Planetoid::applyForce(ofPoint _force){
    ofPoint f = _force / this->mass*2;
    acceleration += f;
};

void Planetoid::checkEdges(){
    float buffer = mass*24;
    if (location.x > ofGetWidth() +  buffer) location.x = -buffer;
    else if (location.x <    -buffer) location.x = ofGetWidth()+buffer;
    if (location.y > ofGetHeight() + buffer) location.y = -buffer;
    else if (location.y <    -buffer) location.y = ofGetHeight()+buffer;
};

void Planetoid::display(){
    ofStroke(pink);
    ofSetLineWidth(2);
    ofFill(mauve, 180);
    ofDrawEllipse(location.x, location.y, mass*24, mass*24);
};

ofPoint Planetoid::attractP(Planetoid _p){
    ofPoint force = location - _p.location);
    float distance= force.length();
    distance = ofClamp(distance, 5.0, 50.0);
    force.normalize();
    float strength = (g * mass * _p.mass) / (distance * distance);
    force *= strength;
    return force;
};

ofPoint Planetoid::attractS(Ship _s){
    ofPoint force = location -  _s.location;
    float distance = force.length();
    distance = ofClamp(distance, 5.0, 70.0);
    force.normalize();
    float strength = (1.0 * mass * _s.mass) / (distance * distance);
    force *= strength;
    return force;
};
