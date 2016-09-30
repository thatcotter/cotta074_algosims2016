#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    points = 0;
    g = 1.0;
    go = 0;
    opaque = 0;
    pink = ofColor(242, 103, 106);
    yellow = ofColor(251, 224, 135);
    lightMauve = ofColor(173, 41, 89);
    mauve = ofColor(98, 1, 60);
    lightGreen = ofColor(166, 242, 219);
    aqua = ofColor(123, 202, 206);
    blue = ofColor(103, 142, 180);
    darkPurp = ofColor(79, 78, 121);
    diedAfter = -0.5;
    
    planetoids.resize(18);
    for (int i = 0; i < 18; i++) {
        planetoids[i].setup(ofRandom(0.5, 1.5), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(darkPurp);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 45; j++) {
            ofSetColor(lightGreen);
            ofDrawEllipse(ofGetWidth()/45*i-60, ofGetWidth()/50*j-45, 1, 1);
        }
    }
    
    
//    for (int i = 0; i < planets.length; i++) {
//        for (int j = 0; j < planets.length; j++) {
//            if (i != j) {
//                
//                float distance = dist(planets[j].location.x, planets[j].location.y, planets[i].location.x, planets[i].location.y);
//                if (distance < 940) {
//                    PVector forceP = planets[j].attract(planets[i]);
//                    planets[i].applyForce(forceP);
//                    planets[i].update();
//                }
//                if (dist(planets[j].location.x, planets[j].location.y, planets[i].location.x, planets[i].location.y) < planets[i].mass*24) {
//                    if (dist(planets[i].location.x, planets[i].location.y, planets[j].location.x, planets[j].location.y) < planets[j].mass*24) {
//                        if (planets[i].velocity.x < planets[i].velocity.y) {
//                            planets[i].velocity.y *= -1;
//                        } else if (planets[i].velocity.x > planets[i].velocity.y) {
//                            planets[i].velocity.x *= -1;
//                        } else {
//                            planets[i].velocity.mult(-1);
//                        }
//                        if (planets[j].velocity.x < planets[j].velocity.y) {
//                            planets[j].velocity.y *= -1;
//                        } else if (planets[j].velocity.x > planets[j].velocity.y) {
//                            planets[j].velocity.x *= -1;
//                        } else {
//                            planets[j].velocity.mult(-1);
//                        }
//                    }
//                }
//                PVector forceS = planets[i].attract(ship);
//                ship.applyForce(forceS);
//            }
//        }
//        if (dist(ship.location.x, ship.location.y+10, planets[i].location.x, planets[i].location.y) < planets[i].mass*24/1.65) {
//            go = 1;
//        }
//        planets[i].wrapEdges();
//        planets[i].display();
//        float distance = abs(dist(ship.location.x, ship.location.y+10, planets[i].location.x, planets[i].location.y));
//        if (distance < 600) {
//            for (int k = 1; k < 2; k++) {
//                float orbit = abs(dist(ship.location.x, ship.location.y+10, planets[i].location.x, planets[i].location.y));
//                int strokeD = int(map( distance, 0, 400, 100, 0));
//                stroke( mauve, strokeD);
//                int strokeW = int(map( planets[i].mass, 0, 2.25, 0, 20));
//                strokeWeight(strokeW);
//                noFill();
//                ellipse(planets[i].location.x, planets[i].location.y, (orbit*2)/k, (orbit*2)/k);
//            }
//        }
//        if (go == 0) {
//            ship.update();
//        }
//    }
//    if (go == 0) {
//        ship.display();
//    }
//    if (go == 1) {
//        ship.update();
//        ship.splode();
//    }
//    noStroke();
//    rectMode(CORNER);
//    fill(mauve);
//    rect(20, 120, 100, 20);
//    int f = int(ship.fuel);
//    fill(pink);
//    textFont(osReg);
//    text("Fuel", 20, 110);
//    rect(20, 120, f, 20);
//    textAlign(LEFT);
//    fill(yellow);
//    text("Z = Thrust", 20, 250);
//    text("Left = Steer", 20, 275);
//    text("Right = Steer", 20, 300);
//    stroke(yellow, 100);
//    line(20, 317, 40, 317);
//    noStroke();
//    text("Velocity", 45, 325);
//    if (keyPressed) {
//        if (key == CODED && keyCode == LEFT) {
//            ship.turn(-0.03);
//        } else if (key == CODED && keyCode == RIGHT) {
//            ship.turn(0.03);
//        }
//    }
//    if (keyPressed) {
//        if (key == 'z' || key == 'Z') {
//            ship.thrust();
//        }
//    }
//    if ( go == 0) {
//        if ( frameCount >= frameRate) {
//            frameCount = 0;
//            diedAfter+= 1;
//        }
//        g = 0.6+diedAfter*0.005;
//        if ( g > 1) g = 1;
//    }
//    if (go == 1) {
//        if (opaque < 225) opaque +=3;
//        fill(darkPurp, opaque);
//        rect(0, 0, width, height);
//        fill(aqua, opaque);
//        textSize(32);
//        text("You died after", (width/8)*1.9+40, height/2-100);
//        text(str(int(diedAfter)), (width/8)*1.9+230, height/2-100);
//        if (diedAfter < 1) {
//            text("seconds in space", (width/8)*1.9+260, height/2-100);
//        } else if (diedAfter > 0 && diedAfter < 2) {
//            text("second in space", (width/8)*1.9+260, height/2-100);
//        } else if (diedAfter > 2 && diedAfter < 10) {
//            text("seconds in space", (width/8)*1.9+260, height/2-100);
//        } else {
//            text("seconds in space", (width/8)*1.9+270, height/2-100);
//        }
//        textFont(cardoItalic);
//        String q = "While there may be some order to the self and the cosmos, to the microcosm and macrocosm, it is an order that is absolutely indifferent to our existence, and of which we can have only a negative awareness.";
//        text(q, (width/8)*1.9+40, height/2.5, width/2.00125, height/1.75);
//        textFont(cardoReg);
//        text("-Eugene Thacker, In the Dust of This Panet", (width/8)*1.9+40, height/1.6);
//        textFont(osBold);
//        fill(pink, opaque);
//        text("Press Enter to try again", (width/8)*1.9+40, height/2+150);
//        if (keyPressed) {
//            if (key == ENTER) {
//                setup();
//            }
//        }
//    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
