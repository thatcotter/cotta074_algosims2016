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
    win = false;
    lose = false;
    level.resize(3);
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
    
    if (pause) {
        if (ofGetKeyPressed(32)) {
            pause = false;
        }
    }
    
    for (int i = 0; i < level.size(); i++) {
        if (level[i] || !pause) {
            if (ofGetKeyPressed(80)) {
                pause = false;
            }
        }
    }
    
}
