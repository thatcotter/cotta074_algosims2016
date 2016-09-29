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
    float g;
    int go;
    int opaque;
    ofColor pink;
    ofColor yellow;
    ofColor lightMauve;
    ofColor mauve;
    ofColor lightGreen;
    ofColor aqua;
    ofColor blue;
    ofColor darkPurp;
    float diedAfter;
};
