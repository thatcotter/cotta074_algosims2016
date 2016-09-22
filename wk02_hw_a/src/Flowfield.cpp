//
//  Flowfield.cpp
//  wk02_hw_a
//
//  Created by Andrew Cotter on 9/12/16.
//
//  baesd on the Nature of Code example by Dan Shiffman

#include "Flowfield.hpp"

Flowfield::Flowfield(){
    
    
}

void Flowfield::setup(int _res){
    resolution = _res;
    
    cols = ofGetWidth()/resolution;
    rows = ofGetHeight()/resolution;
    field.resize(cols);
    for (int i = 0; i < cols; i++){
        field[i].resize(rows);
    }
    init();
    
}

void Flowfield::init() {
    
    float xoff_seed = ofRandom(0,1);
    float yoff_seed = ofRandom(0,1);
    
    float xoff = xoff_seed;
    for (int i = 0; i < cols; i++) {
        float yoff = yoff_seed;
        for (int j = 0; j < rows; j++) {
            float theta = ofMap(ofNoise(xoff,yoff),0,1,0,TWO_PI);
            // Polar to cartesian coordinate transformation to get x and y components of the vector
            field[i][j].set(cos(theta),sin(theta));
            yoff += 0.003;
        }
        xoff += 0.001;
    }
}

void Flowfield::update(){
    float xoff = 0;
    for (int i = 0; i < cols; i++) {
        float yoff = 0;
        for (int j = 0; j < rows; j++) {
            float theta = ofMap(ofNoise(xoff,yoff,zoff),0,1,0,TWO_PI);
            // Polar to cartesian coordinate transformation to get x and y components of the vector
            field[i][j].set(cos(theta),sin(theta));
            yoff += 0.0003;
        }
        xoff += 0.0001;
    }
    // Animate by changing 3rd dimension of noise every frame
    zoff += 0.0001;
}

void Flowfield::display(){
    
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            drawVector(field[i][j],i*resolution,j*resolution,resolution-2);
        }
    }
    
}

void Flowfield::drawVector(const ofVec2f & v, float x, float y, float scayl) {
    ofSetColor(255);
    ofPushMatrix();
    float arrowsize = 4;
    // Translate to location to render vector
    ofTranslate(x,y);
    //stroke(0,100);
    // Call vector heading function to get direction (note that pointing up is a heading of 0) and rotate
    ofRotate(ofVec2f(1,0).angle(v));
    // Calculate length of vector & scale it to be bigger or smaller if necessary
    float len = v.length()*scayl;
    // Draw three lines to make an arrow (draw pointing up since we've rotate to the proper direction)
    ofDrawLine(0,0,len,0);
    ofDrawLine(len,0,len-arrowsize,+arrowsize/2);
    ofDrawLine(len,0,len-arrowsize,-arrowsize/2);
    ofPopMatrix();
}

