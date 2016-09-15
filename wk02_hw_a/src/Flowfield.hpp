//
//  Flowfield.hpp
//  wk02_hw_a
//
//  Created by Andrew Cotter on 9/12/16.
//
//  baesd on the Nature of Code example by Dan Shiffman

#pragma once
#include "ofMain.h"

class Flowfield{
    
public:
    Flowfield();
    void setup(int _res);
    void update();
    void display();
    void drawArrow(float _length);
    float lookup(ofVec2f _lookup);
    
    vector< vector<float> > field;
    
    int cols, rows;
    int resolution;
};