#pragma once

#include "ofMain.h"

#include "StartScreen.hpp"
#include "FlowfieldLevel.hpp"
#include "NewtonianLevel.hpp"
#include "LevelSelect.hpp"

#include "SceneManager.hpp"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

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
    
    void customLevel1(NewtonianLevel lvl1);
    
    SceneManager    scenes;
    StartScreen     start;
    NewtonianLevel  level;
    LevelSelect     selectScreen;
    
    ofSoundPlayer   music;
    
};
