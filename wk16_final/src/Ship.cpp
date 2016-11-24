//
//  Ship.cpp
//  microCosm
//
//  Created by Andrew Cotter on 11/6/16.
//
//

#include "Ship.hpp"


Ship::Ship(){
    
    pos.x = ofGetWidth()*3/2;
    pos.y = ofGetHeight()*3/2;
    mass = 10.0;
    fuel = 1024;
    thetaInc = 4.0;
    rocket.addVertex( ofPoint( 0, 20 ) );
    rocket.addVertex( ofPoint( -10, -5 ) );
    rocket.addVertex( ofPoint( 10, -5 ) );
}

void Ship::draw(){
    
    ofPushMatrix();
    ofTranslate(pos);
    ofRotate(theta);
    
    ofSetColor(255);
    rocket.draw();
    
    ofPopMatrix();
}

void Ship::drawFuel(){
    
    ofNoFill();
    ofSetLineWidth(5);
    ofDrawRectangle(30, 30, 300, 30);
    
    
    ofFill();
    ofSetLineWidth(1);
    ofDrawRectangle(30, 30, ofMap(fuel, 0, 1024, 0, 300), 30);
}

void Ship::update(FlowField field){
    
    ps.update(field);
    this->turn();
    this->thrust();
//    this->checkEdges();
    
    ofPoint forceAtPos = field.getForceAtPosition(this->pos) * 0.005;
    this->applyForce( forceAtPos );
    
    vel += accel;
    pos += vel;
    
    vel *= 0.999;
    
    accel.set(0);
    
    if (boost == false && fuel < 1024) {
        fuel += 0.25;
    }
}

void Ship::turn(){
    if(left){
        theta -= thetaInc;
    }
    if (right) {
        theta += thetaInc;
    }
}

void Ship::thrust(){
    if(boost && fuel > 0){
        float angle = theta + 90;
        ofVec2f force = ofVec2f(1,0).getRotated(angle);
//        force *= 0.5;
        this->applyForce(force);
        force *= -0.6;
        ps.addParticle( pos - ofPoint(0,-5), force );
        fuel -= 1;
    }
}

void Ship::checkEdges(){
    if (pos.x < 0) {
        pos.x = ofGetWidth();
    }
    if (pos.x > ofGetWidth()) {
        pos.x = 0;
    }
    if (pos.y < 0) {
        pos.y = ofGetHeight();
    }
    if (pos.y > ofGetHeight()) {
        pos.y = 0;
    }
}