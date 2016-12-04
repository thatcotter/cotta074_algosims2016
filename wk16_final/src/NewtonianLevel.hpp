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
#include "Camera2D.hpp"
#include "Planetoid.hpp"
#include "StarField.hpp"
#include "ofxGui.h"

class NewtonianLevel{
    
public:
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
    
    
    Ship ship;
    
    Goal goal;
    
    vector<Planetoid> planets;
    
    WinScreen youWin;
    
    bool debug;
    bool win;
    
    ofxPanel        gui;
    ofxFloatSlider  gravity;
    ofxFloatSlider  radius;
    ofxFloatSlider  turning;
    ofxFloatSlider  thrust;
    
    Camera2D        cam;
    
    StarField       background;
};
