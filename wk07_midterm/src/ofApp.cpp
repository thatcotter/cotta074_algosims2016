#include "ofApp.h"

//arduino functions come from the oF firmata example

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    ofBackground(235);
    light.setup();
    
    //arduino stuff
    buttonState = "digital pin:";
    potValue = "analog pin:";
    ard.connect("/dev/tty.usbmodem1421", 57600); //change this based on the actual serial port in the computer
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    bSetupArduino	= false;
    
    //panel stuff
    gui.setup();
    gui.add(coh.setup("cohesion", 1.0, 0.0, 10.0));
    gui.add(ali.setup("allignment", 1.0, 0.0, 10.0));
    gui.add(sep.setup("separation", 1.0, 0.0, 10.0));
    bHide = false;
    
    
    
    //flock setup;
    for (int i = 0; i < 500; i++) {
        Particle temp;
        temp.init();
        flock.push_back(temp);
    }
    
    
    //sound stuff
    for (int i = 0; i < flock.size()/50; i++) {
        double phase = 0;
        phases.push_back(phase);
    }
    updateWaveform(32);
    ofSoundStreamSetup(1, 0); // mono output
}

//--------------------------------------------------------------
void ofApp::setupArduino(const int & version) {
    
    // remove listener because we don't need it anymore
    ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);
    
    // it is now safe to send commands to the Arduino
    bSetupArduino = true;
    
    // print firmware name and version to the console
    ofLogNotice() << ard.getFirmwareName();
    ofLogNotice() << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion();
    
    // Note: pins A0 - A5 can be used as digital input and output.
    // Refer to them as pins 14 - 19 if using StandardFirmata from Arduino 1.0.
    // If using Arduino 0022 or older, then use 16 - 21.
    // Firmata pin numbering changed in version 2.3 (which is included in Arduino 1.0)
    
    
    
    // set pin A0 to analog input
    ard.sendAnalogPinReporting(0, ARD_ANALOG);
    ard.sendAnalogPinReporting(1, ARD_ANALOG);
    ard.sendAnalogPinReporting(2, ARD_ANALOG);
    
    // set pin D11 as PWM (analog output)
    ard.sendDigitalPinMode(11, ARD_PWM);
    
    
    // Listen for changes on the digital and analog pins
    ofAddListener(ard.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(ard.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

//--------------------------------------------------------------
void ofApp::updateArduino(){
    
    // update the arduino, get any data or messages.
    // the call to ard.update() is required
    ard.update();
    
    // do not send anything until the arduino has been set up
    if (bSetupArduino) {
        // fade the led connected to pin D11
        ard.sendPwm(11, (int)(128 + 128 * sin(ofGetElapsedTimef())));   // pwm...
        coh = float(ard.getAnalog(0))/100;
        ali = float(ard.getAnalog(1))/100;
        sep = float(ard.getAnalog(2))/100;
        
    }
    
}

// digital pin event handler, called whenever a digital pin value has changed
// note: if an analog pin has been set as a digital pin, it will be handled
// by the digitalPinChanged function rather than the analogPinChanged function.

//--------------------------------------------------------------

void ofApp::updateWaveform(int waveformResolution) {
    waveform.resize(waveformResolution);
//    waveLine.clear();
    
    // "waveformStep" maps a full oscillation of sin() to the size
    // of the waveform lookup table
    float waveformStep = (M_PI * 2.) / (float) waveform.size();
    
    for(int i = 0; i < waveform.size(); i++) {
        waveform[i] = sin(i * waveformStep);
        
//        waveLine.addVertex(ofMap(i, 0, waveform.size() - 1, 0, ofGetWidth()),
//           ofMap(waveform[i], -1, 1, 0, ofGetHeight()));
    }
}

void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
    ofScopedLock waveformLock(waveformMutex);
    
    float sampleRate = 44100;
    float t = ofGetElapsedTimef();
    float detune = ofMap(sep, 0, 10, 0, 100);
    
    for(int phaseIndex = 0; phaseIndex < phases.size(); phaseIndex++) {
        float phaseFreq = frequency + ofSignedNoise(phaseIndex, t) * detune;
        float phaseStep = phaseFreq / sampleRate;
        
        for(int i = 0; i < bufferSize * nChannels; i += nChannels) {
            phases[phaseIndex] += phaseStep;
            int waveformIndex = (int)(phases[phaseIndex] * waveform.size()) % waveform.size();
            output[i] += waveform[waveformIndex];
        }
    }
    
    outLine.clear();
    for(int i = 0; i < bufferSize * nChannels; i+= nChannels) {
        output[i] /= phases.size();
        outLine.addVertex(ofMap(i, 0, bufferSize - 1, 0, ofGetWidth()),
                          ofMap(output[i], -1, 1, 0, ofGetHeight()));
    }
}

//--------------------------------------------------------------
void ofApp::digitalPinChanged(const int & pinNum) {
    // do something with the digital input. here we're simply going to print the pin number and
    // value to the screen each time it changes
    buttonState = "digital pin: " + ofToString(pinNum) + " = " + ofToString(ard.getDigital(pinNum));
}

// analog pin event handler, called whenever an analog pin value has changed

//--------------------------------------------------------------
void ofApp::analogPinChanged(const int & pinNum) {
    // do something with the analog input. here we're simply going to print the pin number and
    // value to the screen each time it changes
    potValue = "analog pin: " + ofToString(pinNum) + " = " + ofToString(ard.getAnalog(pinNum));
}

//--------------------------------------------------------------
void ofApp::update(){
    
    updateArduino();
    
    for (int i = 0; i < flock.size(); i++) {
        flock[i].coheMult = coh;//apply sliders to flocking values
        flock[i].sepMult = sep;
        flock[i].alliMult = ali;
        flock[i].update(flock);
        flock[i].update(leaders);
        flock[i].bounding();
        
    }
    
    
    ofScopedLock waveformLock(waveformMutex);
    updateWaveform(ofMap(coh, 0, 10, 3, 64, true));
    frequency = ofMap(ali, 0, 10, 60, 700, true);

}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofEnableLighting();
    ofEnableDepthTest();
//    light.enable();
    cam.begin();
    
    
//    ofBackground(42,51,86);
//    ofSetColor(243,91,37,200);
    ofBackground(20);
    ofSetColor(235);
    
//    ofPushMatrix();
    
//    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    for(int i = 0; i < flock.size(); i++){
        flock[i].draw();
    }
    
//    ofSetColor(255);
//    for(int i = 0; i < flock.size(); i++){
//        leaders[i].draw();
//    }
    
//    ofPopMatrix();
    
    cam.end();
//    light.disable();
    ofDisableDepthTest();
//    ofDisableLighting();
    
    if(!bHide){
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'h'){
        bHide = !bHide;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
