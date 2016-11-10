//
//  MeshSphere.hpp
//  wk10_hw_a
//
//  Created by Andrew Cotter on 11/6/16.
//
//

#ifndef MeshSphere_hpp
#define MeshSphere_hpp

#include <stdio.h>
#include "ofMain.h"

class MeshSphere{
    
public:
    MeshSphere();
    void setup();
    void update();
    void draw();
    
    int gridWidth;
    int gridHeight;
    
    int i1, i2, i3, i4;
    
    int num;
    
    vector<ofPoint> points;
    vector<float> theta;
    vector<float> phi;
    
    vector<int> radius;
    
    float dist;
    
    vector<float> changeTheta;
    vector<float> changePhi;
    
    ofMesh mesh;
    bool frame;
};
#endif /* MeshSphere_hpp */
