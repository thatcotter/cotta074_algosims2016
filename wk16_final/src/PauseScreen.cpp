//
//  PauseScreen.cpp
//  voyage
//
//  Created by Andrew Cotter on 12/3/16.
//
//

#include "PauseScreen.hpp"

void PauseScreen::setup(){
    
    reset, menu, pause = false;
    
    opacity = 0;
    delay = 0;
    index = 0;
    
    title.load( "Ubuntu-Medium.ttf", 42 );
    optionText.load( "Ubuntu-Light.ttf", 24 );
    detailText.load( "Ubuntu-Light.ttf", 16 );
    
    options.clear();
    for (int i = 0; i < 2; i++) {
        float temp;
        options.push_back(temp);
    }
    
    options[0] = ofGetHeight()*0.435;
    options[1] = ofGetHeight()*0.485;
    options[2] = ofGetHeight()*0.535;
    
    lvlSelectOptions.clear();
    for (int i = 0; i < 1; i++) {
        float temp;
        lvlSelectOptions.push_back(temp);
    }
//    float temp;
//    lvlSelectOptions.push_back(temp);
    
    lvlSelectOptions[0] = ofGetHeight()*0.435;
    lvlSelectOptions[1] = ofGetHeight()*0.435;
    
}



void PauseScreen::draw(){
    
//    cout << "PauseScreen.draw();" << endl;
    
    ofSetColor(0, 0, 0, opacity);
    
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofSetColor(255, 255, 255, opacity);
    
    title.drawString("Paused", ofGetWidth()*0.24, ofGetHeight()*0.33);
    
    optionText.drawString("Resume", ofGetWidth()*0.24, ofGetHeight()*0.45);
    optionText.drawString("Retry", ofGetWidth()*0.24, ofGetHeight()*0.50);
    optionText.drawString("Menu", ofGetWidth()*0.24, ofGetHeight()*0.55);
    
    
    ofDrawCircle(ofGetWidth()*0.22, options[index], 5);
    
}


void PauseScreen::lvlSelectDraw(){
    
//    cout << "PauseScreen.draw();" << endl;

    
    ofSetColor(0, 0, 0, opacity);
    
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofSetColor(255, 255, 255, opacity);
    
    title.drawString("Paused", ofGetWidth()*0.24, ofGetHeight()*0.33);
    
    optionText.drawString("Resume", ofGetWidth()*0.24, ofGetHeight()*0.45);
//    optionText.drawString("Retry", ofGetWidth()*0.24, ofGetHeight()*0.50);
//    optionText.drawString("Menu", ofGetWidth()*0.24, ofGetHeight()*0.55);
    
    
    ofDrawCircle(ofGetWidth()*0.22, lvlSelectOptions[index], 5);
    
}

void PauseScreen::lvlDraw(float _fuel, float _time){
    
    //    cout << "PauseScreen.draw();" << endl;
    string fuel = to_string(int(_fuel));
    string time = to_string(int(_time));
    
    ofSetColor(255);
    detailText.drawString("Fuel Used: " + fuel + "kg", 50, 50 );
    detailText.drawString("Elapsed Time: " + time + "s", 50, 75 );
//    detailText.drawString("Boost: Space or A Button", 50, 100 );
//    detailText.drawString("Pause: Esc Key or START Button", 50, 125 );
    
}

void PauseScreen::drawInstructions(){
    
    ofSetColor(255);
    detailText.drawString("Controls", 50, 50 );
    detailText.drawString("Turn: Left & Right", 50, 75 );
    detailText.drawString("Boost: Space or A Button", 50, 100 );
    detailText.drawString("Pause: Esc Key or START Button", 50, 125 );
    
}



void PauseScreen::keyPressed(int key){
    
    if (key == OF_KEY_UP) {
        if ( index == 0 ) {
            if (lvlSelect) {
                index = lvlSelectOptions.size();
            } else{
                index = options.size();
            }
        }else{
            index--;
        }
    }
    
    if (key == OF_KEY_DOWN) {
        if ( lvlSelect && index == lvlSelectOptions.size() ) {
            index = 0;
        } else if ( !lvlSelect && index == options.size() ) {
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
                
//                if (lvlSelect) {
//                    //
//                }else{
//                    reset = true;
//                }
            } else{
                if (lvlSelect) {
                    //
                }else{
                    menu = true;
                }
            }
            
        }
    }
}


