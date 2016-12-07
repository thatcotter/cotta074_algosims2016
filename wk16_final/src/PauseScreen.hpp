//
//  PauseScreen.hpp
//  voyage
//
//  Created by Andrew Cotter on 12/3/16.
//
//

#ifndef PauseScreen_hpp
#define PauseScreen_hpp

#include <stdio.h>
#include "WinScreen.hpp"

class PauseScreen : public WinScreen{
public:
    virtual void setup();
    virtual void draw();
    virtual void keyPressed(int key);
    
    bool pause;
};


#endif /* PauseScreen_hpp */
