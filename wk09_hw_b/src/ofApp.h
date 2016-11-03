#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "FlowField.h"
#include "ParticleSystem.hpp"
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
    
    ParticleSystem  system;
    FlowField       field;
    VectorPuck      puck;
    VectorPuck      puck2;
    
    ofFbo           fbo1, fbo2;
    
    bool drag, drag2;
    bool debug;
    
};
