//
//  StartScreen.cpp
//  voyage
//
//  Created by Andrew Cotter on 11/25/16.
//
//

#include "StartScreen.hpp"

StartScreen::StartScreen(){
    time = 0;
    fade.allocate(ofGetWidth(), ofGetHeight());
    titleFont.load( "Serif Gothic Bold.ttf", 64 );
}

void StartScreen::setup(string _title, string _subtitle, string _prompt){
    title = _title;
    subtitle = _subtitle;
    prompt = _prompt;
    time = 0;
    fade.allocate(ofGetWidth(), ofGetHeight());
    
    background.stars.clear();
    background.setup();
}

void StartScreen::update(){
    fade.begin();
    
    ofSetColor(0, 0, 0, 255 - time);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    fade.end();
    
    time++;
}

void StartScreen::draw(){
    
    background.draw();
    
//    ofDrawBitmapString(title, ofGetWidth()/3, ofGetHeight()/3);
    titleFont.drawString(title, ofGetWidth()*0.33, ofGetHeight()*0.5);
//    ofDrawBitmapString(subtitle, ofGetWidth()/3, ofGetHeight()/3+50);
    ofDrawBitmapString(prompt, ofGetWidth()*0.4, ofGetHeight()*0.8);
    
    fade.draw(0,0);
    
}

void StartScreen::keyPressed(int key){
    
    
}
