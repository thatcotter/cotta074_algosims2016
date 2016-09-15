//
//  Flowfield.cpp
//  wk02_hw_a
//
//  Created by Andrew Cotter on 9/12/16.
//
//  baesd on the Nature of Code example by Dan Shiffman

#include "Flowfield.hpp"

Flowfield::Flowfield(){
    
    
}

void Flowfield::setup(int _res){
    resolution = _res;
    
    cols = ofGetWidth()*2/resolution +2;
    rows = ofGetHeight()*2/resolution +2;
    
    float xoff = 0;
    
    for (int i = 0; i < cols; i++) {
        vector<float> tempCol;
        
        float yoff = 0;
        
        for (int j = 0; j < rows; j++) {
            
            float theta = ofRadToDeg( ofMap(ofNoise(xoff,yoff),0,1,0,TWO_PI) );
            
//            cout << theta << endl;
            
            tempCol.push_back(theta);
            
            yoff += 0.03;
        }
        
        field.push_back(tempCol);
        xoff += 0.03;
    }
    
}

void Flowfield::update(){
    
}

void Flowfield::display(){
    
    for(int i=0; i< rows ; i++)
    {
        for(int j=0; j< cols ; j++)
        {
            ofFill();
            ofPushMatrix();
            // add half resolution to each dimension to put us in center of each 'cell'
            ofTranslate((i*resolution) + resolution/2,
                         j*resolution  + resolution/2);
            float angleToRotate = field[i][j];
            ofRotate(angleToRotate);
            drawArrow(resolution);
            ofSetColor(255);
//            int angFloored = angleToRotate;
//             ofDrawBitmapString(ofToString(angFloored), 0,0); // uncomment to output angle at position for debugging
            ofPopMatrix();
        }
    }
    
}

void Flowfield::drawArrow(float _length)
{
    // half the length is subtracted from the x point positions to move the rotation axis to the center
    ofSetColor(255);
    ofDrawLine(-_length/2, 0, _length/2, 0);
    ofDrawLine(-_length/2 + _length*0.8, _length*0.1, _length/2, 0);
    ofDrawLine(-_length/2 + _length*0.8, _length*-0.1, _length/2, 0);
}


float Flowfield::lookup( ofVec2f _lookup){
    int column = int(ofClamp(_lookup.x/resolution,0,cols-1));
    int row = int(ofClamp(_lookup.y/resolution,0,rows-1));
    return field[column][row];
}