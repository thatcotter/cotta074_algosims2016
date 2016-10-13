//
//  path.cpp
//  wk06_hw_b
//
//  Created by Andrew Cotter on 10/11/16.
//
//

#include "path.hpp"

path::path(){
    theta = 0;
    xSpace = 26.0;
    period = 500.0;
    a = 10;
    aInc = 1;
    amplitude = 240.0;
    
    w = ofGetWidth()+44;
    dx = (TWO_PI / period) * xSpace;
    
    for (int i = 0; i < (w/xSpace); i++) {
        float temp;
        yVals.push_back(temp);
    }
}

void path::setup(){
    radius = 30;
    points.resize(yVals.size());
}


void path::addPoint(float x, float y){
    
    ofPoint point(x,y);
    points.push_back(point);
    
}

void path::update(){
    
    theta += 0.02;
    if (a > 243 || a < 10 ) {
        aInc *= -1;
    }
    a+= aInc;
    aa = a % 245;
    
    float x = theta;
    for (int i = 0; i < yVals.size(); i++) {
        yVals[i] = sin(x)*amplitude;
        //        cout << yVals[i] << endl;
        x+=dx;
    }
    
}


void path::draw(){
    
    ofSetColor(255,0,0);
    ofNoFill();
    glLineWidth(radius*2);
    
    ofBeginShape();
    
    for(int i = 0; i < yVals.size(); i++){
        
        //for(ofPoint v: points){
        ofVertex(i*xSpace-40, ofGetHeight()/2+yVals[i]+radius);
    }
    ofEndShape();
    
    
    ofBeginShape();
    
    for(int i = 0; i < yVals.size(); i++){
        
        //for(ofPoint v: points){
        ofVertex(i*xSpace-40, ofGetHeight()/2+yVals[i]-radius);
    }
    ofEndShape();
    
    
    
    ofSetColor(0);
    ofNoFill();
    //glLineWidth(1);
    
    ofBeginShape();
    
    for(int i = 0; i < yVals.size(); i++){
        
        //for(ofPoint v: points){
        ofVertex(i*xSpace-40, ofGetHeight()/2+yVals[i]);
        points[i] = ofPoint(i*xSpace-40, ofGetHeight()/2+yVals[i]);
    }
    
    ofEndShape();
    
}