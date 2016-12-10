//
//  MenuMenuPauseScreen.cpp
//  voyage
//
//  Created by Andrew Cotter on 12/8/16.
//
//

#include "MenuPauseScreen.hpp"


void MenuPauseScreen::setup(){
    
    reset, menu, pause = false;
    
    opacity = 0;
    delay = 0;
    index = 0;
//    title.load( "Ubuntu-Bold.ttf", 42 );
//    optionText.load( "Ubuntu-Light.ttf", 24);
    
    options.clear();
    for (int i = 0; i < 2; i++) {
        float temp;
        options.push_back(temp);
    }
    
    options[0] = ofGetHeight()*0.435;
    options[1] = ofGetHeight()*0.485;
    options[2] = ofGetHeight()*0.535;
    
    
}

void MenuPauseScreen::update(){
    
    if (opacity < 192) {
        opacity+=3;
    }
    
    delay += 1;
    
}


void MenuPauseScreen::draw(){
    
    ofSetColor(0, 0, 0, opacity);
    
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofSetColor(255, 255, 255, opacity);
    
//    title.drawString("Paused", ofGetWidth()*0.24, ofGetHeight()*0.33);
//    
//    optionText.drawString("Resume", ofGetWidth()*0.24, ofGetHeight()*0.45);
//    optionText.drawString("Retry", ofGetWidth()*0.24, ofGetHeight()*0.50);
//    optionText.drawString("Menu", ofGetWidth()*0.24, ofGetHeight()*0.55);
    
    
    ofDrawCircle(ofGetWidth()*0.22, options[index], 5);
    
}



void MenuPauseScreen::keyPressed(int key){
    
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
    
    if (key == OF_KEY_ESC) {
        pause = true;
    }
    
    if (key == ' ' || key == OF_KEY_RETURN) {
        cout << "Paused: index == " << index << endl;
        if (delay >= 60) {
            if ( index == 0 ) {
                pause = false;
            }else if ( index == 1 ) {
                reset = true;
            } else{
                menu = true;
            }
            
        }
    }
}