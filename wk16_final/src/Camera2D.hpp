//
//  Camera2D.hpp
//  microCosm
//
//  Created by Andrew Cotter on 11/19/16.
//
//

#ifndef Camera2D_hpp
#define Camera2D_hpp
#include "ofMain.h"

#include <stdio.h>

class Camera2D{
public:
    Camera2D();
    void setup(ofVec2f _target);
    void update(ofVec2f _target);
    void edges(ofVec2f _target);
    void reCenter(ofVec2f _target);
    
    void xenoToPointX(float _bound, float _target);
    void xenoToPointY(float _bound, float _target);
    
    ofVec2f getOrigin();
    ofVec2f getMinBounds();
    ofVec2f getMaxBounds();
    bool    isInView(ofVec2f _pos, float _offset);
    
    bool    switchDebug();
    
    void begin();
    void end();
    
private:
    
    ofVec2f target;
    
    ofVec2f origin;
    ofVec2f compensate;
    
    float leftOutBound, rightOutBound;
    float upOutBound, downOutBound;
    
    float leftInBound, rightInBound;
    float upInBound, downInBound;
    
    float catchUpSpeed;
    
    bool rightComp, leftComp, upComp, downComp;
    
    bool debug;
    
};

#endif /* Camera2D_hpp */
