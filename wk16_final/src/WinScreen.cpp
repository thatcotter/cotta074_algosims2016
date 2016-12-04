//
//  WinScreen.cpp
//  voyage
//
//  Created by Andrew Cotter on 12/3/16.
//
//

#include "WinScreen.hpp"


WinScreen::WinScreen(){
    
    opacity = 0;
    index = 0;
    title.load( "Ubuntu-Medium.ttf", 42 );
    optionText.load( "Ubuntu-Light.ttf", 24);
    
    for (int i = 0; i < 1; i++) {
        float temp;
        options.push_back(temp);
    }
    
    options[0] = ofGetHeight()*0.405;
    options[1] = ofGetHeight()*0.45;

    reset, menu = false;
}

WinScreen::WinScreen(float _time, float _fuel){
    
}

void WinScreen::setup(){
    
}

void WinScreen::update(){
    
    if (opacity < 192) {
        opacity+=3;
    }
    
}

void WinScreen::draw(){
    
    ofSetColor(0, 0, 0, opacity);
    
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofSetColor(255, 255, 255, opacity);
    
    title.drawString("Objective Reached", ofGetWidth()*0.24, ofGetHeight()*0.33);
    
    optionText.drawString("Retry", ofGetWidth()*0.24, ofGetHeight()*0.45);
    optionText.drawString("Menu", ofGetWidth()*0.24, ofGetHeight()*0.50);
    
    
    ofDrawCircle(ofGetWidth()*0.22, options[index], 5);
    
}

void WinScreen::keyPressed(int key){
    
    if (key == OF_KEY_UP) {
        if ( index == 0 ) {
            index = options.size();
        }else{
            index--;
        }
    }
    
    if (key == OF_KEY_DOWN) {
        if ( index == options.size() ) {
            index = 0;
        }else{
            index++;
        }
    }
    
    if (key == ' ' || key == OF_KEY_RETURN) {
        if (opacity >= 192) {
            if ( index == 0 ) {
                reset = true;
            }else{
                menu = true;
            }
        }
    }
}
