#include "ofApp.h"
#include <cmath>
float prevSpeed;
float prevSpacing;
float prevWeight;
//--------------------------------------------------------------
void ofApp::setup() {
    ofSetBackgroundAuto(false);
    ofBackground(255);
    ofEnableAlphaBlending();

    guldenSnede = ((sqrt(5) - 1) / 2);
    lastX = 0;
    lastY = 0;

    width = ofGetWidth();
    height = ofGetHeight();

    centerX = width * 0.5;
    centerY = height * 0.5;

    minSpeed = 0;
    maxSpeed = 0.1;
    minSpacing = 5;
    maxSpacing = 1024;

    gui.setup("");
    gui.add(speed.set("speed", 0.02, minSpeed, maxSpeed));
    gui.add(spacing.set("spacing", 128, minSpacing, maxSpacing));
}

//--------------------------------------------------------------
void ofApp::update() {
    if (prevSpeed != speed || prevSpacing != spacing)
    {
        clearScreen();
        prevSpeed = speed;
        prevSpacing = spacing;
    }
}

//--------------------------------------------------------------
void ofApp::draw() {

    ofSetColor(0);
    glLineWidth(weight);

    //string date = ofGetTimestampString("%y%m%d");
    //ofBeginSaveScreenAsSVG(date + ".svg");
    for (float frameCount = 0; frameCount < 5000; frameCount++)
    {
        float t = frameCount * speed;
        float posY = abs(frameCount - 2500) * 0.05;

        lastX = centerX;
        lastY = centerY;

        degree = (t * guldenSnede) * 360;
        
        r = sqrt(t) * spacing;
        yrad = ofMap(frameCount, 0, 5000, 0.5, 0.2);
        calculatePoint(width * 0.5, height * 0.5, 1440 - r, fmod(degree, 360), posY);

        if (frameCount != 0)
            ofLine(lastX, lastY, centerX, centerY);
    }
    //ofEndSaveScreenAsSVG();

    gui.draw();
}

//--------------------------------------------------------------
void ofApp::calculatePoint(float x, float y, float r, float graden, float posY) {
    centerX = x + cos(ofDegToRad(graden)) * (r * 0.5);
    centerY = y + sin(ofDegToRad(graden)) * (r * yrad);// -posY;
}

//--------------------------------------------------------------
void ofApp::clearScreen() {
    ofSetColor(255);
    ofFill();
    ofRect(0, 0, width, height);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}