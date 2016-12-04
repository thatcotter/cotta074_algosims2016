//
//  Goal.hpp
//  voyage
//
//  Created by Andrew Cotter on 12/3/16.
//
//

#ifndef Goal_hpp
#define Goal_hpp

#include <stdio.h>
#include "ofMain.h"

class Goal{
    
public:
    Goal();
    void setup(float _x, float _y);
    void update();
    void draw();
    void drawHint(ofVec2f _pos);
    bool collide(ofVec2f collider);
    
    ofVec2f pos;
    float   radius;
};

#endif /* Goal_hpp */
