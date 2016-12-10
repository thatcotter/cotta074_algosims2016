//
//  StartScreen.hpp
//  voyage
//
//  Created by Andrew Cotter on 11/25/16.
//
//

#ifndef StartScreen_hpp
#define StartScreen_hpp

#include <stdio.h>
#include "ofMain.h"
#include "StarField.hpp"

class StartScreen{
public:
    StartScreen();
    void setup(string _title, string _subtitle, string _prompt);
    void update();
    void draw();
    void keyPressed(int key);
    
    float time;
    string title;
    string subtitle;
    string prompt;
    
    ofFbo fade;
    
    ofTrueTypeFont titleFont;
    
    StarField   background;
    
};

#endif /* StartScreen_hpp */
