//
//  flowfield.h
//  algo_week_08_04_moreParticlesinVectorFields
//
//  Created by Bernardo Santos Schorr on 10/21/13.
//
//

#pragma once

#include "ofMain.h"

class Flowfield {
public:
    
    void setup (int _width, int _height, int _depth, int _resolution);
    void update ();
    void draw ();
    void setPerlin();
    ofVec3f getForceAtPosition( ofVec3f pos );
    void addAttractForce(float x, float y, float z, float radius, float strength);
    
    int width, height, depth, resolution;
    vector < vector< vector<ofVec3f> > > flowList;
    
};