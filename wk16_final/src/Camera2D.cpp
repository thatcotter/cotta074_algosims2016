//
//  Camera2D.cpp
//  microCosm
//
//  Created by Andrew Cotter on 11/19/16.
//
//

#include "Camera2D.hpp"

Camera2D::Camera2D(){
    
    leftOutBound = ofGetWidth() * 0.2;
    rightOutBound = ofGetWidth() * 0.8;
    
    upOutBound = ofGetHeight() * 0.2;
    downOutBound = ofGetHeight() * 0.8;
    
    leftInBound = ofGetWidth() * 0.25;
    rightInBound = ofGetWidth() * 0.75;
    
    upInBound = ofGetHeight() * 0.25;
    downInBound = ofGetHeight() * 0.75;
    
    rightComp, leftComp, upComp, downComp = false;
    
    catchUpSpeed = 0.13;
    
}

void Camera2D::setup(ofVec2f _target){
    
    target = _target;
    
}

void Camera2D::update(ofVec2f _target){
    
    target = _target;
    
    this->edges(target);
    this->reCenter(target);
    
}

void Camera2D::edges(ofVec2f _target){
    
    if( _target.x > rightOutBound ){
        rightComp = true;
    }else if( _target.x < rightInBound ){
        rightComp = false;
    }
    
    if( _target.x < leftOutBound ){
        leftComp = true;
    }else if( _target.x > leftInBound ){
        leftComp = false;
    }
    
    if( _target.y < upOutBound ){
        upComp = true;
    }else if( target.y > upInBound ){
        upComp = false;
    }
    
    if( _target.y > downOutBound ){
        downComp = true;
    }else if( _target.y < downInBound ){
        downComp = false;
    }
    
}

void Camera2D::reCenter(ofVec2f _target){
    
    if(rightComp){
        xenoToPointX( rightInBound, _target.x );
    }
    if(leftComp){
        xenoToPointX( leftInBound, _target.x );
    }
    if(upComp){
        xenoToPointY( upInBound, _target.y );
    }
    if(downComp){
        xenoToPointY( downInBound, _target.y );
    }
    
}

void Camera2D::xenoToPointX(float _bound, float _target){
    
    float oldBound = _bound;
    _bound = catchUpSpeed * _target + (1-catchUpSpeed) *_bound;
    float deltaBound = _bound - oldBound;
    cout << deltaBound << endl;
    
    rightInBound += deltaBound;
    rightOutBound += deltaBound;
    leftOutBound += deltaBound;
    leftInBound += deltaBound;
    origin.x -= deltaBound;
    
}

void Camera2D::xenoToPointY(float _bound, float _target){
    
    float oldBound = _bound;
    _bound = catchUpSpeed * _target + (1-catchUpSpeed) *_bound;
    float deltaBound = _bound - oldBound;
//    cout << deltaBound << endl;
    
    upInBound += deltaBound;
    upOutBound += deltaBound;
    downInBound += deltaBound;
    downOutBound += deltaBound;
    origin.y -= deltaBound;
    
}

ofVec2f Camera2D::getOrigin(){
    return this->origin;
}

bool Camera2D::switchDebug(){
    this->debug = !this->debug;
}

void Camera2D::begin(){
    
    ofPushMatrix();
    ofTranslate(origin.x, origin.y);
    
}

void Camera2D::end(){
    
    if(debug){
        ofSetColor(255, 0, 0);
        ofDrawLine(leftOutBound, upOutBound, rightOutBound, upOutBound);
        ofDrawLine(leftOutBound, downOutBound, rightOutBound, downOutBound);
        ofDrawLine(leftOutBound, upOutBound, leftOutBound, downOutBound);
        ofDrawLine(rightOutBound, upOutBound, rightOutBound, downOutBound);
        
        ofSetColor(255);
        ofDrawLine(leftInBound, upInBound, rightInBound, upInBound);
        ofDrawLine(leftInBound, downInBound, rightInBound, downInBound);
        ofDrawLine(leftInBound, upInBound, leftInBound, downInBound);
        ofDrawLine(rightInBound, upInBound, rightInBound, downInBound);
    }
    
    ofPopMatrix();
    
}