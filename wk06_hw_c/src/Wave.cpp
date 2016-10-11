//
//  Wave.cpp
//  wk06_hw_c
//
//  Created by Andrew Cotter on 10/10/16.
//
//

#include "Wave.hpp"

Wave::Wave(){
    
    theta = 0;
    xSpace = 26.0;
    period = 500.0;
    a = 10;
    aInc = 1;
    amplitude = 120.0;
    
    w = ofGetWidth()+44;
    dx = (TWO_PI / period) * xSpace;
    
    for (int i = 0; i < (w/xSpace); i++) {
        float temp;
        yVals.push_back(temp);
    }
    
    
}

void Wave::update(){
    
    theta += 0.02;
    if (a > 243 || a < 10 ) {
        aInc *= -1;
    }
    a+= aInc;
    aa = a % 245;
    
    float x = theta;
    for (int i = 0; i < yVals.size(); i++) {
        yVals[i] = sin(x)*amplitude;
//        cout << yVals[i] << endl;
        x+=dx;
    }
    
}

void Wave::draw(){
    
    for (int i = 0; i < yVals.size(); i++) {
//        stroke(255,255,255,aa);
        
//        ofTranslate(-10, 0);
        
        int div = 16;
        
        ofDrawEllipse(i*xSpace-40, ofGetHeight()/2+yVals[i], 27+ yVals[i]/div, 27 + yVals[i]/div);
        ofSetColor(255,52,127);
        
        ofDrawEllipse(i*xSpace*1.3-40, ofGetHeight()/2+yVals[i], 24+ yVals[i]/div, 24+ yVals[i]/div);
        ofSetColor(201,53,108);
        
        ofDrawEllipse(i*(xSpace*1.6)-40, ofGetHeight()/2+yVals[i], 21+ yVals[i]/div, 21+ yVals[i]/div);
        ofSetColor(244,141,180);
        
        ofDrawEllipse(i*(xSpace*1.9)-40, ofGetHeight()/2+yVals[i], 18+ yVals[i]/div, 18+ yVals[i]/div);
        ofSetColor(119,100,198);
        
        ofDrawEllipse(i*(xSpace*2.1)-40, ofGetHeight()/2+yVals[i], 15+ yVals[i]/div, 15+ yVals[i]/div);
        ofSetColor(110,100,198);
        
        ofDrawEllipse(i*(xSpace*2.4)-40, ofGetHeight()/2+yVals[i], 12+ yVals[i]/div, 12+ yVals[i]/div);
        ofSetColor(255,52,127);
        
        ofDrawEllipse(i*(xSpace*2.7)-40, ofGetHeight()/2+yVals[i], 9+ yVals[i]/div, 9+ yVals[i]/div);
        ofSetColor(201,53,108);
        
        ofDrawEllipse(i*(xSpace*3.0)-40, ofGetHeight()/2+yVals[i], 6+ yVals[i]/div, 6+ yVals[i]/div);
        ofSetColor(244,141,180);
    }
    
}