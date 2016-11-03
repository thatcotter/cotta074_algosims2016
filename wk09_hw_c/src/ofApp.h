#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ParticleSystem.hpp"
#include "Flowfield.h"
#include "VectorPuck.hpp"

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
    
    ofTrueTypeFont          fontSmall;
    
    ofxPanel				gui;
    
    ofParameter<int>		numParticles;
    ofParameter<float>		randomOffset;
    ofParameter<float>		noiseMagnitude;
    ofParameter<float>		spaceFrequency;
    ofParameter<float>		timeFrequency;
    ofParameter<float>		oldVelAmount;
    ofParameter<float>		maxVel;
    ofParameter<float>		maxAge;
    bool					drawGui;
    bool                    drawField;
    bool                    drag;
		
    ParticleSystem          pSysytem;
    Flowfield               field;
    VectorPuck              puck;
    
    ofEasyCam               cam;
};
