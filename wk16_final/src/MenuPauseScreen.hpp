//
//  MenuPauseScreen.hpp
//  voyage
//
//  Created by Andrew Cotter on 12/8/16.
//
//

#ifndef MenuPauseScreen_hpp
#define MenuPauseScreen_hpp

#include <stdio.h>
#include "PauseScreen.hpp"

class MenuPauseScreen{
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    bool pause;
    
    float   opacity;
    float   delay;
    int     index;
    
    vector<float>  options;
    
    bool reset;
    bool menu;
    
//    ofTrueTypeFont title;
//    ofTrueTypeFont optionText;
};

#endif /* MenuPauseScreen_hpp */
