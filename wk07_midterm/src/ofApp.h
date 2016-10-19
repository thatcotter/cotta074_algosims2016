#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#include "ofxGui.h"
#include "Particles.h"

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
    
        vector<Particle> flock;
    
//        vector<Particle> leaders;
    
        ofEasyCam cam;
        ofLight light;
    
        ofxPanel gui;
        ofxFloatSlider sep;
        ofxFloatSlider ali;
        ofxFloatSlider coh;
        bool bHide;
    
        ofArduino ard;
        bool bSetupArduino;
    
        void updateWaveform(int waveformResolution);
        void audioOut(float * output, int bufferSize, int nChannels);
        vector<float> waveform;
        vector<double> phases;
        float frequency;
        
        ofMutex waveformMutex;
        ofPolyline waveLine;
        ofPolyline outLine;
    
    private:
        void setupArduino(const int & version);
        void digitalPinChanged(const int & pinNum);
        void analogPinChanged(const int & pinNum);
        void updateArduino();
        
        string buttonState;
        string potValue;
		
};
