#pragma once

#include "ofMain.h"
#include "ParticleSystem.hpp"
#include "VectorPuck.hpp"
#include "Ship.hpp"
#include "Camera2D.hpp"
#include "FieldGrid.hpp"
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
    
    FlowField       field;
    FieldGrid       grid;
    
    
    vector<VectorPuck> pucks;
    
    Ship ship;
    
    ofFbo           fbo1, fbo2;
    
    bool debug;
    
    ofxPanel        gui;
    ofxFloatSlider  gravity;
    ofxFloatSlider  radius;
    ofxFloatSlider  turning;
    
    Camera2D        cam;
    
//    ofImage         styleTile;
//    bool            present;
};
