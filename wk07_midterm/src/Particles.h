//
//  Particles.h
//  myFlocking
//
//  Based on class example by Regina Flores on 10/6/16.
//
//
#pragma once
#include "ofMain.h"


class Particle{
public:
    
    Particle();
    
    void init();
    void bounding();
    void draw();

    //this is more of a software design question.
    //many ways to wrtie software and solve a probelem
    
    //passing in a reference of a vector of particles
    //these are not pointers
    //these are references
    
    //why couldnt i just pass in the vector itself? why do i need a ref?
    //because c++ would make a copy by default and that would be memory intensive. Also, if you create another copy of the object then when you pass in your array of paarticles the addresses are different. So you cant refer to the actual particle, its like a new set of particles. 
    void update( vector<Particle> &particles );
    
    void flock( vector<Particle> &particles );
    
    void seek(ofPoint target);
    void avoid(ofPoint target);
    void arrive(ofPoint target);
    
    ofPoint steer(ofPoint target, bool slowdown);

    ofPoint cohesion(vector<Particle> &particles);
    ofPoint separation(vector<Particle> &particles);
    ofPoint allignment(vector<Particle> &particles);
    bool inView(Particle &particle);
    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    
    float coheMult, sepMult, alliMult;
    
    float damp;
    
    int radius;
//    float r;
    float maxforce;
    float maxspeed;

};