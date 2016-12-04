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
    void draw();
    void keyPressed(int key); 

    float   opacity;
    int     index;
    
    vector<float>  options;
    
    bool reset;
    bool menu;
    
    ofTrueTypeFont title;
    ofTrueTypeFont optionText;
};

#endif /* WinScreen_hpp */
