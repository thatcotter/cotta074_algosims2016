//
//  FieldGrid.hpp
//  microCosm
//
//  Created by Andrew Cotter on 11/19/16.
//
//

#ifndef FieldGrid_hpp
#define FieldGrid_hpp
#include "ofMain.h"
#include "FlowField.h"
#include "Camera2D.hpp"

#include <stdio.h>

class FieldGrid{
public:
    FieldGrid();
    void setup();
    void update();
    void draw(Camera2D _cam);
    
    vector<vector<FlowField>> tiles;
    
    int rows, cols;
    
    float width, height;
    
    ofPoint origin;
};

#endif /* FieldGrid_hpp */
