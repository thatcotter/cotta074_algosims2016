//
//  flowfield.cpp
//  algo_week_08_04_moreParticlesinVectorFields
//
//  Created by Bernardo Santos Schorr on 10/21/13.
//
//

#include "Flowfield.h"


void Flowfield::setup ( int _width, int _height, int _depth, int _resolution ) {
    
    width = _width;
    height = _height;
    depth = _depth;
    resolution = _resolution;
    
    int cols = width / resolution;
    int rows = height/resolution;
    int layers = depth / resolution;
    
    for (int z = 0; z < layers; z++) {
        vector< vector<ofVec3f> > myPlaneList;
        flowList.push_back ( myPlaneList );
        
        for (int y = 0; y < rows; y++) {
            vector<ofVec3f> myList;
            flowList[z].push_back ( myList );
            
            for (int x = 0; x < cols; x++) {
                ofVec3f dir( 5, 5, 5 );
                flowList[z][y].push_back ( dir );
            }
        }
    }
}

void Flowfield::update(){
    for( int z = 0; z < flowList.size(); z++){
        for( int y = 0; y < flowList[z].size(); y++){
            for( int x=0; x<flowList[z][y].size(); x++){
                flowList[z][y][x] *= 0.99;
                
                if( flowList[z][y][x].length() < 1.0){
                    flowList[z][y][x].normalize();
                }
            }
        }
    }
}

void Flowfield::draw () {
    for( int z = 0; z < flowList.size(); z++){
        for( int y = 0; y < flowList[z].size(); y++){
            for( int x=0; x<flowList[z][y].size(); x++){
                ofVec3f np( x*resolution, y*resolution, z*resolution );
                ofDrawLine ( np, np+flowList[z][y][x] );
            }
        } 
    }
}

void Flowfield::setPerlin() {
    for( int z = 0; z < flowList.size(); z++){
        for( int y=0; y<flowList[z].size(); y++){
            for( int x=0; x<flowList[z][y].size(); x++){
                float noise = ofMap( ofNoise(x*0.1, y*0.1, z*0.1), 0, 1, 0, TWO_PI);
                float cotNoise = cos(noise)/sin(noise);
                flowList[z][y][x].set( ofVec3f( cos(noise) * 20.0, sin(noise) * 20.0, sin (noise) * 20.0 ) );
            }
        }
    }
}

ofVec3f Flowfield::getForceAtPosition( ofVec3f pos ){
    float pctX = pos.x / width;
    float pctY = pos.y / height;
    float pctZ = pos.z / depth;
    
    int cols = width / resolution;
    int rows = height / resolution;
    int layers = depth / resolution;
    
    int xVal = ofClamp( pctX * cols, 0, cols-1 );
    int yVal = ofClamp( pctY * rows, 0, rows-1 );
    int zVal = ofClamp( pctZ * layers, 0, layers-1 );
    
    ofVec3f newPos;
    newPos.set( flowList[zVal][yVal][xVal] );
    
    return newPos;
}

void Flowfield::addAttractForce(float x, float y, float z, float radius, float strength) {
    
    float pctX = x / width;
    float pctY = y / width;
    float pctZ = z / width;
    
    int cols = width / resolution;
    int rows = height / resolution;
    int layers = depth / resolution;
    
    int xVal = pctX * cols;
    int yVal = pctY * rows;
    int zVal = pctZ * layers;
    
    ofVec3f puckPos(x, y, z);
    
    for( int z = 0; z < flowList.size(); z++){
        for( int y=0; y<flowList[z].size(); y++){
            for( int x=0; x<flowList[z][y].size(); x++){
                ofVec3f np( x*resolution, y*resolution, z*resolution );
                
                if( np.distance(puckPos) < radius ){
                    float pct = 1 - (np.distance(puckPos) / radius);
                    
                    // add strength against the direction it's already moving in
                    //                flowList[y][x] -= flowList[y][x].normalized() * strength;
                    
                    // add strength towards the puck
                    ofVec3f dir = (np - puckPos);
                    flowList[z][y][x] -= dir.getNormalized() * strength;
                }
            }
        }
    }
}
