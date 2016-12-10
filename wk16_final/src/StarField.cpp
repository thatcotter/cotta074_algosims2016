//
//  StarField.cpp
//  voyage
//
//  Created by Andrew Cotter on 11/30/16.
//
//

#include "StarField.hpp"


StarField::StarField(){
    
}

void StarField::setup(){
    
    for (int i = 0; i < 20000; i++) {
        ofVec2f temp;
        temp = ofVec2f(ofRandom(-ofGetWidth()*10, ofGetWidth()*10),
                       ofRandom(-ofGetHeight()*10, ofGetHeight()*10));
        stars.push_back(temp);
    }
    
}

void StarField::shuffle(){
    
}

void StarField::update(){
    
}

void StarField::draw(){
    
    ofSetColor(255);
    for (int i = 0; i < stars.size(); i++) {
        ofDrawEllipse(stars[i].x, stars[i].y, 2, 2);
    }
    
}