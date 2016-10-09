//
//  Spring.cpp
//  springsPointers
//
//  Created by Regina Flores on 9/29/16.
//
//

#include "Spring.hpp"

Spring::Spring(){

    
    A = NULL;
    B = NULL;
    
    k = 0.5;

}

void Spring::set(Particle *_A, Particle *_B){

    A = _A;
    B = _B;
    
    //New notation:
    //"->" if you have a pointer to an object and you want to call that object's funtion
    
    restDist = A->pos.distance(B->pos);
//    cout << restDist << endl;
}

void Spring::update(){

    if(A == NULL || B == NULL){
        return;
    }
    
    //pointer notation to implement Hooke's Law
    //steps of making the spring "springy"
    ofPoint force = A->getPosition() - B->getPosition();
    
//    cout << force << endl;
    
    float currentLength = force.length();
    float x = currentLength - restDist;
    
    //Tao and Nick vector math working group
    force.normalize();
    
//    cout << force << endl;

    
    force *= k *x; //hookes law
    
    if(A->bFix){
        A->addForce(-force*0.5);
    }
    
    B->addForce(force*0.5);
    
//    cout << force << endl;
    
}

void Spring::draw(){
    
    if(A == NULL || B == NULL){
        return;
    }
    
    ofDrawLine(A->getPosition(), B->getPosition());
}










