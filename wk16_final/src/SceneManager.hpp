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

class SceneManager{
    
public:
    SceneManager();
    virtual void setup();
    virtual void update(LevelSelect _menu);
    
    bool start;
    bool levelSelect;
    
    vector<bool> level;
    
};

#endif /* SceneManager_hpp */
