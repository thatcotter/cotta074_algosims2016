//
//  SceneManager.cpp
//  voyage
//
//  Created by Andrew Cotter on 11/24/16.
//
//

#include "SceneManager.hpp"

SceneManager::SceneManager(){
    start = true;
    levelSelect = false;
    level.resize(24);
}

void SceneManager::setup(){
    
}

void SceneManager::update(LevelSelect _menu){
    
    if (start) {
        if (ofGetKeyPressed()) {
            start = false;
            levelSelect = true;
        }
    }
    
    if (levelSelect) {
        for (int i = 0; i < _menu.planets.size(); i++) {
            if (_menu.selectedLevel[i]) {
                levelSelect = false;
                level[i] = true;
//                cout << "scenemanger: level " << i + 1 << endl;
                break;
            }
        }
    }
    

    
}
