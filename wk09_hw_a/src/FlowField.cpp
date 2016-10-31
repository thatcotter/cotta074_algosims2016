//
//  FlowField.cpp
//  VectorField
//
//  Created by Charlie Whitney on 10/7/13.
//
//

#include "FlowField.h"

FlowField::FlowField() {
    
}

void FlowField::setup( int width, int height, int res ) {
    fieldWidth = width;
    fieldHeight = height;
    resolution = res;
    zOff = 0.0;
    zOffSpeed = 0.001;
    
    cols = fieldWidth / resolution;
    rows = fieldHeight / resolution;
    
    // Make a big list of forces.  We will store them in a 2 dimensional vector.
    flowList.clear();
    for( int y=0; y<rows; y++){
        vector<ofVec2f> myList;
        flowList.push_back( myList );
        
        for( int x=0; x<rows; x++){
            ofVec2f dir(1,0);
            flowList[y].push_back( dir );
        }
    }
}

// Set all the forces in the field to random values
void FlowField::setRandom() {
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            flowList[y][x].set( ofRandom(-1,1), ofRandom(-1,1) );
        }
    }
}

// Set all the forces in the field based on perlin noise
void FlowField::setPerlin() {
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            float noise = ofMap( ofNoise(x*0.005, y*0.005), 0, 1, 0, TWO_PI);
            flowList[y][x].set( ofVec2f( cos(noise), sin(noise) ) );
        }
    }
}

void FlowField::update(){
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            float noise = ofMap( ofNoise(x*0.01, y*0.03, zOff), 0, 1, 0, TWO_PI);
            flowList[y][x].set( ofVec2f( cos(noise), sin(noise) ) );
        }
    }
    zOff += zOffSpeed;
}

void FlowField::drawRipple(){
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            
            ofVec2f pos( x*((fieldWidth*1.25)/flowList.size())+resolution/2, y*((fieldHeight*1.25)/flowList.size())+resolution/2 );
            float ang= abs(flowList[y][x].x - flowList[y][x].y);
//            cout << ang << endl;
            
            int b = abs(flowList[y][x].x*255/2 + flowList[y][x].y*255/2);
            ofSetColor(b, 64);
            ofDrawCircle(pos, ang*resolution*1.2);
            
        }
    }
}

void FlowField::draw() {
    for( int y=0; y<flowList.size(); y++){
        for( int x=0; x<flowList[y].size(); x++){
            ofVec2f np( x*((fieldWidth*1.25)/flowList.size())+resolution/2, y*((fieldHeight*1.25)/flowList.size())+resolution/2 );
            drawVectorAt( flowList[y][x], np );
        }
    }
}

void FlowField::drawVectorAt( const ofVec2f &vec, const ofVec2f &pos ) {
    ofVec2f np = pos - (vec.normalized()) * 5.0;
    drawVector( np, np + vec.normalized() * 10.0, 5, 3 );
}

/**
 * This is a complicated one!  It's a translation of the one right out of the Cinder source, no need to understand it,
 * but it's an interesting one to look at anyway!
 * https://github.com/cinder/Cinder/blob/master/src/cinder/gl/gl.cpp line 915 if you're interested
 */
void FlowField::drawVector( const ofVec3f &start, const ofVec3f &end, float headLength, float headRadius ) {
	const int NUM_SEGMENTS = 32;
	float lineVerts[3*2];
	ofVec3f coneVerts[NUM_SEGMENTS+2];
	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexPointer( 3, GL_FLOAT, 0, lineVerts );
	lineVerts[0] = start.x; lineVerts[1] = start.y; lineVerts[2] = start.z;
	lineVerts[3] = end.x; lineVerts[4] = end.y; lineVerts[5] = end.z;
	glDrawArrays( GL_LINES, 0, 2 );
	
	// Draw the cone
	ofVec3f axis = ( end - start ).normalized();
    ofVec3f temp = ( axis.dot( ofVec3f(0,1,0) ) > 0.999f ) ? axis.crossed( ofVec3f(1,0,0) ) : axis.crossed( ofVec3f(0,1,0) );
	ofVec3f left = ofVec3f(axis.crossed( temp )).normalized();
	ofVec3f up = axis.crossed( left ).normalized();
    
	glVertexPointer( 3, GL_FLOAT, 0, &coneVerts[0].x );
	coneVerts[0] = ofVec3f( end + axis * headLength );
	for( int s = 0; s <= NUM_SEGMENTS; ++s ) {
		float t = (float)s / (float)NUM_SEGMENTS;
		coneVerts[s+1] = ofVec3f( end + left * headRadius * cos( t * 2.0f * 3.14159f )
                                 + up * headRadius * sin( t * 2.0f * 3.14159f ) );
	}
	glDrawArrays( GL_TRIANGLE_FAN, 0, NUM_SEGMENTS+2 );
    
	// draw the cap
	glVertexPointer( 3, GL_FLOAT, 0, &coneVerts[0].x );
	coneVerts[0] = end;
	for( int s = 0; s <= NUM_SEGMENTS; ++s ) {
		float t = s / (float)NUM_SEGMENTS;
		coneVerts[s+1] = ofVec3f( end - left * headRadius * (float)cos( t * 2 * 3.14159f )
                                 + up * headRadius * (float)sin( t * 2 * 3.14159f ) );
	}
	glDrawArrays( GL_TRIANGLE_FAN, 0, NUM_SEGMENTS+2 );
    
	glDisableClientState( GL_VERTEX_ARRAY );
}