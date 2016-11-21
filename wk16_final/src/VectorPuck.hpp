//
//  VectorPuck.hpp
//  wk09_hw_b
//
//  Created by Andrew Cotter on 11/1/16.
//
//

#ifndef VectorPuck_hpp
#define VectorPuck_hpp

#include <stdio.h>
#include "ofMain.h"
#include "FlowField.h"

class VectorPuck{
    
public:
    VectorPuck();
    void setup();
    void update(FlowField &field);
    void display();
    
    ofPoint pos;
    ofPoint force;
    float radius;
    float strength;
    
    bool drag;
    
};

#endif /* VectorPuck_hpp */
