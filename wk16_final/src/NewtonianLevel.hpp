//
//  NewtonianLevel.hpp
//  voyage
//
//  Created by Andrew Cotter on 11/25/16.
//
//

#pragma once

#include "ofMain.h"
#include "ParticleSystem.hpp"
#include "Ship.hpp"
#include "Goal.hpp"
#include "WinScreen.hpp"
#include "PauseScreen.hpp"
#include "Camera2D.hpp"
#include "Planetoid.hpp"
#include "StarField.hpp"
#include "ofxGui.h"

class NewtonianLevel{
    
public:
//    void setup(ofTrueTypeFont _title, ofTrueTypeFont _optionText, ofTrueTypeFont _scoreText);
    void setup();
    void update();
    
    void levelSetup(int lvl);
    
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
    
    void fadeInUpdate();
    void fadeOutUpdate();
    void fadeInterpolate(float _pct);
    void fadeDraw();
    
    float fadeOpacity;
    float pct;
    float fadePct;
    
    Ship ship;
    
    Goal goal;
    
    int  currentLevel;
    
    vector<Planetoid> planets;
    
    WinScreen youWin;
    
    bool debug;
    bool win;
    bool exit;
    
    float startTime;
    
    float fuelUsed;
    int elapsedTime;
    
    ofxPanel        gui;
    ofxFloatSlider  gravity;
    ofxFloatSlider  radius;
    ofxFloatSlider  turning;
    ofxFloatSlider  thrust;
    
    Camera2D        cam;
    
    StarField       background;
    
    ofTrueTypeFont title;
    ofTrueTypeFont optionText;
    ofTrueTypeFont scoreText;
};
