#include "Particle.h"

Particle::Particle() {
    pos.x = ofGetWindowWidth()*0.5;
    pos.y = ofGetWindowHeight()*0.5;
    pos.z = 0.0;
    
    vel.set(0,0,0);
    acc.set(0,0,0);
    
    damp = 0.95; // de resistance!!!
    radius = 5;
}

void Particle::setInit(ofPoint _pos, ofPoint _vel){
    pos = _pos;
    vel = _vel;
    acc.set(0,0,0);
}

ofPoint Particle::getPosition(){
    return pos;
}

float Particle::getRadius(){
    return radius;
}

void Particle::addForce(ofPoint _force){
    acc += _force;
}

void Particle::addRepulsionForce(ofPoint _pos, float _rad, float _scale){
    
    ofPoint diff = _pos - pos;
    if( diff.length() < _rad ){
        diff *= 1.0-diff.length()/_rad;// PRO way
        addForce(-diff*_scale);
    }
}

void Particle::addAttractionForce(ofPoint _pos, float _rad, float _scale){
    ofPoint diff = _pos - pos;
    if( diff.length() < _rad ){
        diff *= 1.0-diff.length()/_rad;
        addForce(diff*_scale);
    }
}

void Particle::seek( ofPoint dest ) {
    float maxSpeed = 10.0;
    float maxForce = 0.4;
    
    float slowDownRadius = 200.0;
    
    ofPoint desired = dest - pos;
    
    if( desired.length() < slowDownRadius ){
        float newMag = ofMap( desired.length(), 0, slowDownRadius, 0, maxSpeed);
        
        desired.normalize();
        desired *= newMag;
    }else{
        desired.normalize();
        desired *= maxSpeed;
    }
    
    ofPoint steer = desired - vel;
    steer.limit( maxForce );
    
    addForce( steer );
}

void Particle::update() {
    
    vel += acc;
    vel *= damp;
    pos += vel;
    acc *= 0.0;
    
    if( pos.x < 0.0 || pos.x > ofGetWidth() ){
        pos.x -= vel.x; // Bounced back! think of this as an undo;
        vel.x *= -1.0;
    }
    
    if( pos.y < 0.0 || pos.y > ofGetHeight()+(radius+2) ){
        pos.y -= vel.y; // Bounced back! think of this as an undo;
        vel.y *= -1.0;
    }
}

void Particle::draw() {
//    ofCircle(pos, radius);
    
    ofSetRectMode( OF_RECTMODE_CENTER );
    
    ofPushMatrix();
    ofTranslate( pos );
    
//    float rotAmt = atan2( vel.y, vel.x );
//    ofRotate( ofRadToDeg(rotAmt) + 90 );
//    ofDrawRectangle( 0,0, 20, 40);
//    
//    ofPopMatrix();
    
    float rotAmt = atan2( vel.y, vel.x );
    ofRotate( ofRadToDeg(rotAmt) + 90 );
    
    ofBeginShape();
    ofTranslate(0, -60);
    for (int i = 80; i >= 0; i -= 20) {
        // for (var i = 0; i < 180; i+=20){
        int x = sin(ofWrapRadians(i)) * i /3;
        int angle = cos(ofWrapRadians(i + ofGetFrameNum())) ;
        // var angle = sin(radians(i+this.s)) * 50;
        ofVertex(-x, i);
        ofVertex(-x, i);
    }
    
    for (int i = 0; i <= 80; i += 20) {
        int x = sin(ofWrapRadians(i)) * i /3;
        int angle = cos(ofWrapRadians(i + ofGetFrameNum())) ;
        // var angle = sin(radians(i+this.s)) * 50;
        ofVertex(x, i);
        ofVertex(x, i);
    }
    ofEndShape();
    
    ofPopMatrix();
    
}