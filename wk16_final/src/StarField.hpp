//
//  StarField.hpp
//  voyage
//
//  Created by Andrew Cotter on 11/30/16.
//
//

#ifndef StarField_hpp
#define StarField_hpp

#include <stdio.h>
#include "ofMain.h"

class StarField{
    
public:
    StarField();
    void setup();
    void shuffle();
    void update();
    void draw();
    
    vector<ofVec2f> stars;
    
};

#endif /* StarField_hpp */
