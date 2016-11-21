#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofToggleFullscreen();
    
    cam.setup(ship.pos);
    
    ofBackground(64);
    ofSetFrameRate(60);
    
    gui.setup();
    gui.add(gravity.setup("gravity", 1.5, 0.0, 3.0));
    gui.add(radius.setup("radius", 200.0, 0.0, 1000.0));
    gui.add(turning.setup("turning speed", 3.6, 0.01, 8.0));
    
    fbo1.clear();
    fbo2.clear();
    
    fbo1.allocate( ofGetWidth()*3, ofGetHeight()*3 );
    fbo2.allocate( ofGetWidth()*3, ofGetHeight()*3 );
    
    field.setup( ofGetWidth()*3, ofGetHeight()*3, 24 );
//    grid.setup();
    
    for (int i = 0; i < 12; i++) {
        VectorPuck vp;
        vp.pos = ofPoint(ofRandom(ofGetWidth()*3),ofRandom(ofGetHeight()*3));
        vp.drag = false;
        pucks.push_back(vp);
    }
    
    debug = false;
    
//    styleTile.load("voyage_style_tile.jpg");
//    present = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    std::stringstream strm;
    strm << "fps: " << ofGetFrameRate();
    ofSetWindowTitle(strm.str());
    
    for (int i = 0; i < pucks.size(); i++) {
        pucks[i].strength = gravity;
        pucks[i].radius = radius;
        pucks[i].update(field);
//        for (int i = 0; i < grid.tiles.size(); i++) {
//            for (int j = 0; j < grid.tiles[i].size(); j++){
//                ofVec2f lowerBounds = grid.tiles[i][j].origin;
//                ofVec2f upperBounds = grid.tiles[i][j].origin
//                + ofVec2f(ofGetWidth(),ofGetHeight());
//                if ( pucks[i].pos.x > lowerBounds.x && pucks[i].pos.y > lowerBounds.y ) {
//                    if ( pucks[i].pos.x < upperBounds.x && pucks[i].pos.y < upperBounds.y ) {
//                        pucks[i].update(grid.tiles[i][j]);
//                    }
//                }
//            }
//        }
    }
    
    ship.thetaInc = turning;
    ship.update(field);
//    for (int i = 0; i < grid.tiles.size(); i++) {
//        for (int j = 0; j < grid.tiles[i].size(); j++){
//            ofVec2f lowerBounds = grid.tiles[i][j].origin;
//            ofVec2f upperBounds = grid.tiles[i][j].origin
//                                + ofVec2f(ofGetWidth(),ofGetHeight());
//            if ( ship.pos.x > lowerBounds.x && ship.pos.y > lowerBounds.y ) {
//                if ( ship.pos.x < upperBounds.x && ship.pos.y < upperBounds.y ) {
//                    ship.update(grid.tiles[i][j]);
//                }
//            }
//        }
//    }
    
    ship.turn();
    field.update();
//    for (int i = 0; i < grid.tiles.size(); i++) {
//        for (int j = 0; j < grid.tiles[i].size(); j++){
//            grid.tiles[i][j].update();      
//        }
//    }

    cam.update(ship.pos);
    
    fbo1.begin();
    ofClear(0,0,0,20);
    ship.ps.display();
    fbo1.end();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    fbo2.begin();
    fbo1.draw(0,0);
    fbo2.end();
    fbo2.draw(0,0);
    
    if (debug) {
        field.draw();
//        for (int i = 0; i < grid.tiles.size(); i++) {
//            for (int j = 0; j < grid.tiles[i].size(); j++){
//                grid.tiles[i][j].draw();
//            }
//        }
    }
    
    for (int i = 0; i < pucks.size(); i++) {
        pucks[i].display();
    }
    
    ship.draw();
    
    cam.end();
    
    if (debug) {
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == OF_KEY_TAB){
        debug = !debug;
        cam.switchDebug();
    }
    if(key == OF_KEY_LEFT){
        ship.left = true;
    }
    if(key == OF_KEY_RIGHT){
        ship.right = true;
    }
    if(key == 13 || key == 32){
        ship.boost = true;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == OF_KEY_LEFT){
        ship.left = false;
    }
    if(key == OF_KEY_RIGHT){
        ship.right = false;
    }
    if(key == 13 || key == 32){
        ship.boost = false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    for (int i = 0; i < pucks.size(); i++) {
        if (pucks[i].drag) {
            pucks[i].pos = ofPoint(x,y) - cam.getOrigin();
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
//    if (present == false) {
    
        for (int i = 0; i < pucks.size(); i++) {
            if (x > pucks[i].pos.x-20+cam.getOrigin().x && x < pucks[i].pos.x+20+cam.getOrigin().x) {
                if (y > pucks[i].pos.y-20+cam.getOrigin().y && y < pucks[i].pos.y+20+cam.getOrigin().y) {
                    pucks[i].drag = true;
                }
            }
        }
//    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//    if (present == false) {
        for (int i = 0; i < pucks.size(); i++) {
            pucks[i].drag = false;
        }
//    }
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
