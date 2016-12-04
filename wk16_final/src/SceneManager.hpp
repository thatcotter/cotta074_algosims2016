//
//  SceneManager.hpp
//  voyage
//
//  Created by Andrew Cotter on 11/24/16.
//
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <stdio.h>
#include "ofMain.h"
#include "LevelSelect.hpp"

class SceneManager : public ofBaseApp{
    
public:
    SceneManager();
    virtual void setup();
    virtual void update(LevelSelect _menu);
//    void keyPressed(int key);
    
    bool start;
    bool levelSelect;
    bool win;
    bool lose;
    bool pause;
    
    vector<bool> level;
    
};

#endif /* SceneManager_hpp */
