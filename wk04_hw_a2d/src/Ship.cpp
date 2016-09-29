//
//  Ship.cpp
//  wk05_hw_a2d
//
//  Created by Andrew Cotter on 9/28/16.
//
//

#include "Ship.hpp"
Ship::Ship() {
    location = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    velocity = ofPoint(0, 0);
    acceleration = ofPoint(0,0);
    mass = 15;
    ps = *new ParticleSystem();
}
void update() {
    velocity += acceleration;
    velocity *= damping;
    velocity.limit(topspeed);
    location += velocity;
    acceleration *= 0.5;
    ps.run();
}
void applyForce(PVector force) {
    PVector f = force.copy();
    f.div(mass);
    acceleration.add(f);
}

void turn(float a) {
    heading += a*6;
}
void splode() {
    ps.addParticle(location.x, location.y+r, PVector.random2D());
}
void thrust() {
    if (fuel > 0) {
        float angle = heading - PI/2;
        PVector force = PVector.fromAngle(angle+random(-0.05, 0.05));
        force.mult(0.5);
        applyForce(force);
        force.mult(-.6);
        ps.addParticle(location.x, location.y+r, force.mult(.5));
        thrusting = true;
        fuel -= 1;
    } else {
        fuel= -0.1;
    }
    thrusting = false;
}
void wrapEdges() {
    float buffer = r*2;
    if (location.x > width +  buffer) location.x = -buffer;
    else if (location.x <    -buffer) location.x = width+buffer;
    if (location.y > height + buffer) location.y = -buffer;
    else if (location.y <    -buffer) location.y = height+buffer;
}
void display() {
    stroke(blue);
    strokeWeight(1);
    pushMatrix();
    translate(location.x, location.y+r);
    rotate(heading);
    rect(-r/2-1, r, r/2, r/2);
    rect(r/2-1, r, r/2, r/2);
    fill(lightGreen);
    beginShape();
    vertex(-r, r);
    vertex(-r+1, -r+5);
    vertex(0, -r);
    vertex(-r+11, -r+5);
    vertex(r, r);
    endShape(CLOSE);
    rectMode(CENTER);
    popMatrix();
    stroke(yellow, 100);
    strokeWeight(3);
    line(location.x, location.y+8, location.x + velocity.x*60, (location.y+8)+velocity.y*60);
    thrusting = false;
    fuel += .1;
    if (fuel > 100) {
        fuel =100;
    }
}