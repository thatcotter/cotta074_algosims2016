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
    void init();
    void update();
    void display();
    void drawVector(const ofVec2f & v, float x, float y, float scayl);
    
    ofVec2f lookup(const ofVec2f & lookup) const {
        int column = int(ofClamp(lookup.x/resolution,0,cols-1));
        int row = int(ofClamp(lookup.y/resolution,0,rows-1));
        return field[column][row];
    }
    
    vector< vector<ofVec2f> > field;
    
    int cols, rows;
    int resolution;
    
//    float xoff = 0.0;
//    float yoff = 0.0;
    float zoff = 0.0;
};