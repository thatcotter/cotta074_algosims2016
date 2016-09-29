#pragma once

#include "ofMain.h"
#include "Planetoid.hpp"
#include "Ship.hpp"
#include "Particle.hpp"
#include "ParticleSystem.hpp"

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
		
    vector<Planetoid> planetoids;
    
    Ship ship;
    
    float points;
    float g = 1.0;
    int go = 0;
    int opaque = 0;
    ofColor pink = "#F2676A";
    ofColor yellow = "#FBE087";
    ofColor lightMauve = "#AD2959";
    ofColor mauve = "#62013C";
    ofColor lightGreen = "#A6F2DB";
    ofColor aqua = "#7BCACE";
    ofColor blue = "#678EB4";
    ofColor darkPurp = "#4F4E79";
    float diedAfter = -0.5;
};
