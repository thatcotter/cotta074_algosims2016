//
//  Goal.cpp
//  voyage
//
//  Created by Andrew Cotter on 12/3/16.
//
//

#include "Goal.hpp"

Goal::Goal(){
    pos = ofVec2f(ofRandom(-ofGetWidth()*5, ofGetWidth()*5),
                  ofRandom(-ofGetHeight()*5, ofGetHeight()*5));
    radius = 35;
}

void Goal::setup(float _x, float _y){
    
    this->pos = ofVec2f( _x, _y );
    
}

void Goal::update(){
    
}

void Goal::draw(){
    
    
    ofSetColor(247,56,89);
    ofDrawRectangle(this->pos.x-(radius/2), this->pos.y-(radius/2),
                    radius, radius);
    
}

void Goal::drawHint(ofVec2f _pos){
    
    ofVec2f center = ofVec2f( ofGetWidth()/2,
                              ofGetHeight()/2 );
    ofVec2f distance = _pos - this->pos;
    float lineDistance = distance.length();
    
    distance.normalize();
    
    distance *= 30;
    
//    ofSetColor(255, 0, 0);
//    ofDrawLine( _pos, this->pos );
//    
//    ofSetColor(0, 255, 0);
//    ofDrawLine( _pos, (_pos - distance) );
    
    ofSetColor(247,56,89);
    for (int i = 1; i < lineDistance/30; i+=2) {
        ofDrawCircle((_pos - distance*(i)), 3);
    }
    

}

bool Goal::collide(ofVec2f _pos){
    
    ofVec2f force = this->pos - _pos;
    float distance= force.length();
    
    if (distance < radius) {
        return true;
        cout << "Goal: COLLISION" << endl;
    }else{
        return false;
    }
    
}