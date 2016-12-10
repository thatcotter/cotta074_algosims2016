//
//  WinScreen.cpp
//  voyage
//
//  Created by Andrew Cotter on 12/3/16.
//
//

#include "WinScreen.hpp"


WinScreen::WinScreen(){
    
    reset, menu = false;
    
    opacity = 0;
    delay = 0;
    index = 0;
    title.load( "Ubuntu-Medium.ttf", 42 );
    optionText.load( "Ubuntu-Light.ttf", 24);
    scoreText.load("Ubuntu-LightItalic.ttf", 64);
    
    for (int i = 0; i < 1; i++) {
        float temp;
        options.push_back(temp);
    }
    
    options[0] = ofGetHeight()*0.405;
    options[1] = ofGetHeight()*0.45;

//    cout << "WIN: reset == " << reset << endl;
    
}

WinScreen::WinScreen(float _time, float _fuel){
    
}

//void WinScreen::setup(ofTrueTypeFont _title, ofTrueTypeFont _optionText, ofTrueTypeFont _scoreText){
void WinScreen::setup(){
    
//    title = _title;
//    optionText = _optionText;
//    scoreText = _scoreText;
    
    reset, menu = false;
    opacity = 0;
    delay = 0;
    index = 0;
    
}

void WinScreen::update(){
    
    if (opacity < 192) {
        opacity+=3;
    }
    
    delay += 1;
    
}

void WinScreen::draw(string _fuel, string _time){
    
    ofSetColor(0, 0, 0, opacity);
    
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofSetColor(255, 255, 255, opacity);
    
    title.drawString("Objective Reached", ofGetWidth()*0.24, ofGetHeight()*0.33);
    
    optionText.drawString("Retry", ofGetWidth()*0.24, ofGetHeight()*0.45);
    optionText.drawString("Menu", ofGetWidth()*0.24, ofGetHeight()*0.50);
    
    ofDrawCircle(ofGetWidth()*0.22, options[index], 5);
    
    optionText.drawString("Fuel Used", ofGetWidth()*0.4, ofGetHeight()*0.45);
    scoreText.drawString( _fuel + " kg", ofGetWidth()*0.4, ofGetHeight()*0.58);
    
    optionText.drawString("Elapsed Time", ofGetWidth()*0.4, ofGetHeight()*0.65);
    scoreText .drawString( _time + " s", ofGetWidth()*0.4, ofGetHeight()*0.78 );
    
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
        if (delay >= 60) {
            if ( index == 0 ) {
                reset = true;
            }else{
                menu = true;
            }
        }
    }
}
