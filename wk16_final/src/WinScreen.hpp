//
//  WinScreen.hpp
//  voyage
//
//  Created by Andrew Cotter on 12/3/16.
//
//

#ifndef WinScreen_hpp
#define WinScreen_hpp

#include <stdio.h>
#include "ofMain.h"

class WinScreen{
    
public:
    WinScreen();
    WinScreen(float _time, float _fuel);
    void setup();
    void update();
    void draw(string _fuel, string _time);
    void keyPressed(int key); 

    float   opacity;
    float   delay;
    int     index;
    
    vector<float>  options;
    
    bool reset;
    bool menu;
    
    ofTrueTypeFont title;
    ofTrueTypeFont optionText;
    ofTrueTypeFont scoreText;
};

#endif /* WinScreen_hpp */
