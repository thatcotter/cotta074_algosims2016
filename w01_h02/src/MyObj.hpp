//
//  MyObj.hpp
//  w01_h01
//
//  Created by Andrew Cotter on 9/1/16.
//
//

#pragma once //just do this don't ase questions for now

#include "ofMain.h"
#include "ofApp.h"


class MyObj{
    
    
public:
    
    void draw();
    void setSrc( float _x, float _y );
    void setDist( float _x, float _y );
    
    void updatePct( float _pct );
    
    void powUpdatePct( float _pct, float _shaper );
    
    
private:
    
    ofPoint src, dst;
    ofPoint pos;
    
    
};