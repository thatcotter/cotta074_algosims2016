//
//  Vehicle.hpp
//  wk06_hw_b
//
//  Created by Andrew Cotter on 10/11/16.
//
//

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Path.hpp"

class vehicle{
    
public:
    bool debug;
    
    void setup(ofPoint & l, float ts, float mf);
    void applyForce(const ofPoint & force);
    void follow(path p);
    ofPoint getNormalPoint(ofPoint p, ofPoint a, ofPoint b);
    void seek(const ofPoint & target);
    void borders();
    void update();
    void draw();
    
    
private:
    ofPoint predictLoc;
    ofPoint normal;
    ofPoint target;
    
    ofPoint location;
    ofPoint velocity;
    ofPoint acceleration;
    float topSpeed;
    float maxForce;
    int r, cor;
    
    float radius;
    float worldRecord;
    
};

#endif /* Vehicle_hpp */
