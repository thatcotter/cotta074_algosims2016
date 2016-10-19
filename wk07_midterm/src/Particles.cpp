//
//  Particles.cpp
//  myFlocking
//
//  Based on class example by Regina Flores on 9/25/14.
//
//

#include "Particles.h"


Particle::Particle(){
    
    radius = 3;
    damp = 0.9;
//    r = 3.0;
    maxspeed = 1.5;
    maxforce = 0.1;

}

//-------------------------------------

void Particle::init(){
    
    //defining the position and velocity of the particles
    //Note: we translate origin (0,0) to middle of screen
    pos = ofPoint(ofRandom(-ofGetWidth()/2, ofGetWidth()/2),ofRandom(-ofGetHeight()/2, ofGetHeight()/2), 0);

    vel.set(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-0.1, 0.1));
    
    acc.set( 0, 0, 0 );
    
    coheMult = 1.0;
    sepMult = 1.0;
    alliMult = 1.0;
    
}

//-------------------------------------

void addFace(ofMesh& mesh, ofVec3f a, ofVec3f b, ofVec3f c) {
    ofVec3f normal = ((b - a).cross(c - a)).normalize();
    mesh.addNormal(normal);
    mesh.addVertex(a);
    mesh.addNormal(normal);
    mesh.addVertex(b);
    mesh.addNormal(normal);
    mesh.addVertex(c);
}

//-------------------------------------

void Particle::draw(){
    
    ofDrawCircle(pos.x, pos.y, radius);

    
//    float sc = radius;
//    ofPushStyle();
//    
//    ofMesh mesh;
//    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
//    
//    addFace(mesh, ofVec3f(3*sc,0,0), ofVec3f(-3*sc,2*sc,0), ofVec3f(-3*sc,-2*sc,0));
//    addFace(mesh, ofVec3f(3*sc,0,0), ofVec3f(-3*sc,2*sc,0), ofVec3f(-3*sc,0,2*sc));
//    addFace(mesh, ofVec3f(3*sc,0,0), ofVec3f(-3*sc,0,2*sc), ofVec3f(-3*sc,-2*sc,0));
//    addFace(mesh, ofVec3f(-3*sc,0,2*sc), ofVec3f(-3*sc,2*sc,0), ofVec3f(-3*sc,-2*sc,0));
//    ofPushMatrix();
//    ofTranslate(pos);
//    ofRotateY(ofRadToDeg(atan2(-vel.z,vel.x)));
//    ofRotateZ(ofRadToDeg(asin(vel.y/vel.length())));
//    
//    mesh.drawFaces();
//    
//    ofPopMatrix();
//    ofPopStyle();

}

//-------------------------------------

//NOTE: Flocking Rules
// each particle compares his state (i.e position and vel) to others to change velocity
//we pass the vector of particles into the update function
//http://www.kfish.org/boids/pseudocode.html


void Particle::flock(vector<Particle> &particles) {
    ofPoint sep = separation(particles);
    ofPoint ali = allignment(particles);
    ofPoint coh = cohesion(particles);
    
    // Arbitrarily weight these forces
    coh *= coheMult;
    sep *= sepMult;
    ali *= alliMult;
    
    acc += sep + ali + coh;
}

ofPoint Particle::cohesion(vector<Particle> &particles){

    //RULE 1
    //finding the center of mass of the system
    float neighbordist = 50.0;
    ofPoint sum;   // Start with empty vector to accumulate all locations
    int count = 0;
    for (int i = 0 ; i < particles.size(); i++) {
        Particle &other = particles[i];
        float d = ofDist(pos.x, pos.y, pos.z, other.pos.x, other.pos.y, other.pos.z);
        if ((d > 0) && (d < neighbordist)) {
            sum += other.pos; // Add location
            count++;
        }
    }
    if (count > 0) {
        sum /= (float)count;
        return steer(sum, false);  // Steer towards the location
    }
    return sum;
}

//-------------------------------------

ofPoint Particle::separation(vector<Particle> &particles){
    //RULE 2
    //particles keep a small distance from each other
    
    float desiredseparation = 25.0f;
    ofVec2f steer;
    int count = 0;
    
    // For every boid in the system, check if it's too close
    for (int i = 0 ; i < particles.size(); i++) {
        Particle &other = particles[i];
        
        float d = ofDist(pos.x, pos.y, other.pos.x, other.pos.y);
        
        // If the distance is greater than 0 and less than an arbitrary amount (0 when you are yourself)
        if ((d > 0) && (d < desiredseparation)) {
            // Calculate vector pointing away from neighbor
            ofVec2f diff = pos - other.pos;
            diff /= d;			// normalize
            diff /= d;        // Weight by distance
            steer += diff;
            count++;            // Keep track of how many
        }
    }
    // Average -- divide by how many
    if (count > 0) {
        steer /= (float)count;
    }
    
    
    // As long as the vector is greater than 0
    //float mag = sqrt(steer.x*steer.x + steer.y*steer.y);
    
    float mag = sqrt(steer.x*steer.x + steer.y*steer.y);
    if (mag > 0) {
        // Implement Reynolds: Steering = Desired - Velocity
        steer /= mag;
        steer *= maxspeed;
        steer -= vel;
        steer.x = ofClamp(steer.x, -maxforce, maxforce);
        steer.y = ofClamp(steer.y, -maxforce, maxforce);
    }
    return steer;
}

//-------------------------------------

ofPoint Particle::allignment(vector<Particle> &particles){

    //RULE 3
    //match velocity
    
    float neighbordist = 50.0;
    ofPoint steer;
    int count = 0;
    for (int i = 0 ; i < particles.size(); i++) {
        Particle &other = particles[i];
        
        float d = ofDist(pos.x, pos.y, pos.z, other.pos.x, other.pos.y, other.pos.z);
        if ((d > 0) && (d < neighbordist)) {
            steer += (other.vel);
            count++;
        }
    }
    if (count > 0) {
        steer /= (float)count;
    }
    
    // As long as the vector is greater than 0
    float mag = sqrt(steer.x*steer.x + steer.y*steer.y + steer.z*steer.z);
    if (mag > 0) {
        // Implement Reynolds: Steering = Desired - Velocity
        steer /= mag;
        steer *= maxspeed;
        steer -= vel;
        steer.x = ofClamp(steer.x, -maxforce, maxforce);
        steer.y = ofClamp(steer.y, -maxforce, maxforce);
        steer.z = ofClamp(steer.z, -maxforce, maxforce);
    }
    return steer;
    
}

//-------------------------------------

bool Particle::inView(Particle &particle){
    // How far can it see?
    float sightDistance = 25;
    float periphery = PI/4;
    
    // A vector that points to another boid and that angle
    ofPoint comparison = particle.pos - this->pos;
    
    // How far is it
    float d = this->pos.distance(particle.pos);
    
    // What is the angle between the other boid and this one's current direction
    float diff = comparison.angle( this->vel );
    
    // If it's within the periphery and close enough to see it
    if (diff < periphery && d > 0 && d < sightDistance) {
        // Just change its color
        // particles[i].highlight();
        return true;
    } else{
        return false;
    }
}

//-------------------------------------

// A method that calculates a steering vector towards a target
// Takes a second argument, if true, it slows down as it approaches the target
ofPoint Particle::steer(ofPoint target, bool slowdown) {
    ofPoint steer;  // The steering vector
    ofPoint desired = target - pos;  // A vector pointing from the location to the target
    
    float d = ofDist(target.x, target.y, target.z, pos.x, pos.y, pos.z); // Distance from the target is the magnitude of the vector
    
    
    // If the distance is greater than 0, calc steering (otherwise return zero vector)
    if (d > 0) {
        
        desired /= d; // Normalize desired
        // Two options for desired vector magnitude (1 -- based on distance, 2 -- maxspeed)
        if ((slowdown) && (d < 100.0f)) {
            desired *= maxspeed * (d/100.0f); // This damping is somewhat arbitrary
        } else {
            desired *= maxspeed;
        }
        // Steering = Desired minus Velocity
        steer = desired - vel;
        steer.x = ofClamp(steer.x, -maxforce, maxforce); // Limit to maximum steering force
        steer.y = ofClamp(steer.y, -maxforce, maxforce);
        steer.z = ofClamp(steer.z, -maxforce, maxforce);
        
    }
    return steer;
}

//-------------------------------------

void Particle::bounding(){
    
    //keeping the particles inside the screen
    //note: the new screen width is (-w/2,w/2), same for height
    if(pos.y > ofGetHeight()/2+50 || pos.y < -ofGetHeight()/2-50){
        vel.y = -vel.y;
    }
    if(pos.x > ofGetWidth()/2+50 || pos.x < -ofGetWidth()/2-50){
        vel.x = -vel.x;
    }
    if(pos.z > 0 || pos.z < ofGetWidth()*2){
        vel.z = -vel.z;
    }
    
//    if (pos.x < -radius) {
//        pos.x = ofGetWidth()+radius;
//    }
//    if (pos.y < -radius){
//        pos.y = ofGetHeight()+radius;
//    }
//    
//    if (pos.x > ofGetWidth()+radius) pos.x = -radius;
//    if (pos.y > ofGetHeight()+radius) pos.y = -radius;
    
}

//-------------------------------------

void Particle:: update( vector<Particle> &particles ){
    
    flock(particles);
    
    vel += acc;   // Update velocity
    vel.x = ofClamp(vel.x, -maxspeed, maxspeed);  // Limit speed
    vel.y = ofClamp(vel.y, -maxspeed, maxspeed);  // Limit speed
    pos += vel;
    acc.set(0,0);  // Reset accelertion to 0 each cycle
    
}


