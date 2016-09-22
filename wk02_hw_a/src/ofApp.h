//sound sample courtesy of NASA


#pragma once

#include "ofMain.h"
#include "Flowfield.hpp"
#include "Vehicle.hpp"
#include "ofxAssimpModelLoader.h"

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
		
    void toroid( int numc, int numt );
    
    Flowfield flowField;
    vector<Vehicle> vehicles;

    void draw3D();
    ofSpherePrimitive sphere;
    ofSpherePrimitive earth;
    
    ofEasyCam cam;
    ofLight light;
    ofMaterial material;
    ofMaterial emfMat;
    
    ofFbo fbo;
//    ofGLRenderer renderer;
    
    bool isDebugMode;
    ofSoundPlayer emf;
    ofTrueTypeFont myfont;
    
    float titleAlpha;
//    ofxAssimpModelLoader torus;
    
};
