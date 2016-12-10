//
//  LevelSelect.hpp
//  voyage
//
//  Created by Andrew Cotter on 11/28/16.
//
//

#ifndef LevelSelect_hpp
#define LevelSelect_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ParticleSystem.hpp"
#include "Ship.hpp"
#include "Camera2D.hpp"
#include "Planetoid.hpp"
#include "StarField.hpp"
#include "PauseScreen.hpp"
#include "ofxGui.h"

class LevelSelect{
    
public:
    LevelSelect();
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    bool anyLvlPicked();
    
    void fadeInUpdate();
    void fadeOutUpdate();
    void fadeInterpolate(float _pct);
    void fadeDraw();
    
    void drawControls();
    
    float fadeOpacity;
    float pct;
    float fadePct;
    bool fadeIn;
    bool fadeOut;
    
    Ship            ship;
        
    vector<Planetoid> planets;
    
    bool debug;
    
    ofxPanel        gui;
    ofxFloatSlider  gravity;
    ofxFloatSlider  radius;
    ofxFloatSlider  turning;
    ofxFloatSlider  thrust;
    
    Camera2D        cam;
    
    int             numLevels;
    
    vector<bool>    selectedLevel;
    
    StarField       background;
    
};

#endif /* LevelSelect_hpp */
