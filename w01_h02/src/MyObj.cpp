//
//  MyObj.cpp
//  w01_h01
//
//  Created by Andrew Cotter on 9/1/16.
//
//

#include "MyObj.hpp"



void MyObj::setSrc( float _x, float _y ){
    
    src.set( _x,  _y );
    
}


void MyObj::setDist( float _x, float _y ){
    
    dst.set( _x, _y );
    
}


//pct = powf(num,exp); myPoss = (1-pct) * a + pct * b;

void MyObj::powUpdatePct( float _pct, float _shaper ){
    
    float _Powpct = powf( _pct, _shaper );
    pos = dst * _Powpct + src * ( 1.0 - _pct );
    
}


void MyObj::draw(){
    
    ofSetColor( 255, 255, 255, 200 );
    ofDrawLine( src, dst );
    
    ofSetColor( 255, 0, 0 );
    ofDrawCircle( pos, 10 );
    
}




