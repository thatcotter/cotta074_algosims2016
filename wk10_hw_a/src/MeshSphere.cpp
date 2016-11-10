//
//  MeshSphere.cpp
//  wk10_hw_a
//
//  Created by Andrew Cotter on 11/6/16.
//
//

#include "MeshSphere.hpp"

MeshSphere::MeshSphere(){
    
    gridWidth = 16;
    gridHeight = 16;
    
    num = gridWidth * gridHeight;
    
    for(int i = 0; i < num; i++){
        ofPoint p; //temp
        points.push_back(p);
        
        float t;
        theta.push_back(t);
        
        float ph;
        phi.push_back(ph);
        
        int r;
        radius.push_back(r);
        
        //changing angles
        float chph;
        changePhi.push_back(chph);
        
        float cht;
        changeTheta.push_back(cht);
        
        
        
        //Make the sphere:
        
        
        theta[i] = ofRandom(0,2*PI);
        phi[i] = ofRandom(0, PI);
        radius[i] = ofRandom(180, 220);
        
        //ofPoint( X, y, z)
        
        points[i] = ofPoint(
                            radius[i]*sin(phi[i])*cos(theta[i]),
                            radius[i]*sin(phi[i])*sin(theta[i]),
                            radius[i]*cos(phi[i])
                            );
        
    }
    
    
    //make a grid of connected lines
    //which are really this notion of vertices
    for(int i = 0; i< points.size(); i++){
        
        //create our mesh:
        mesh.addVertex(points[i]);
        ofColor rand;
        rand.setHsb(ofRandom(255),255,255);
        mesh.addColor(rand);
        
    }
    
    //create the triangle indices
    for(int y=0; y < gridWidth-1; y++){
        for(int x=0; x< gridHeight-1; x++){
            //loop through the squares to get the indices
            i1 = x + gridWidth * y;
            i2 = x+1 + gridWidth * y;
            i3 = x + gridWidth * (y+1);
            i4 = x+1 + gridWidth * (y+1);
            
            mesh.addTriangle(i1, i2, i3);
            mesh.addTriangle(i2, i3, i4);
        }
    }
    
    
    
}

void MeshSphere::setup(){
    
}

void MeshSphere::update(){
    
    
}

void MeshSphere::draw(){
    
    if(frame){
        mesh.drawWireframe();
    }else{
        mesh.draw();
    }
    
}
