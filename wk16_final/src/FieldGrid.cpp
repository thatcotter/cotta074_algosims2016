//
//  FieldGrid.cpp
//  microCosm
//
//  Created by Andrew Cotter on 11/19/16.
//
//

#include "FieldGrid.hpp"

FieldGrid::FieldGrid(){
    
    rows = 3;
    cols = 3;
    
}

void FieldGrid::setup(){
    
    width = ofGetWidth() * rows;
    height = ofGetHeight() * cols;
    
    origin.x = ( ofGetWidth()/2 ) - ( width/2 );
    origin.y = ( ofGetHeight()/2 ) - ( height/2 );
    
    for (int i = 0; i < rows; i++) {
        
        vector<FlowField> tempVec;
        
        for (int j = 0; j < cols; j++) {
            
            FlowField tempFlow;
            tempFlow.setup(ofGetWidth(), ofGetHeight(), 24);
            ofPoint o = ofPoint(ofGetWidth()*i, ofGetHeight()*j);
            tempFlow.origin = this->origin + o;
            tempVec.push_back(tempFlow);
            
        }
        
        tiles.push_back(tempVec);
        
    }
    
}

void FieldGrid::update(){
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tiles[i][j].update();
        }
    }
    
}

void FieldGrid::draw(){
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tiles[i][j].draw();
        }
    }
    
}