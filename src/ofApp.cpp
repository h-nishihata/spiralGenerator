#include "ofApp.h"
#include <cmath>
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

    curPosX = width * 0.5;
    curPosY = height * 0.5;

    gui.setup("");
    gui.add(speed.set("speed", 0.02, 0, 0.1));
    gui.add(spacing.set("spacing", 128, 5, 1024));
    gui.add(count.set("count", 5000, 500, 8000));
    gui.add(yNoise.set("noise", false));
}

//--------------------------------------------------------------
void ofApp::update() {
    if (prevSpeed != speed || prevSpacing != spacing || prevCount != count || prevNoise != yNoise)
    {
        clearScreen();
        prevSpeed = speed;
        prevSpacing = spacing;
        prevCount = count;
        prevNoise = yNoise;
    }
}

//--------------------------------------------------------------
void ofApp::draw() {

    ofSetColor(0);
    glLineWidth(1);

    //string date = ofGetTimestampString("%y%m%d");
    //ofBeginSaveScreenAsSVG(date + ".svg");
    for (float frameCount = 0; frameCount < count; frameCount++)
    {
        float t = frameCount * speed;
        float noiseY = abs(frameCount - 2500) * 0.03;

        lastX = curPosX;
        lastY = curPosY;

        degree = (t * guldenSnede) * 360;
        
        r = sqrt(t) * spacing;
        radY = ofMap(frameCount, 0, 5000, 0.5, 0.2);
        calculatePoint(width * 0.5, height * 0.5, 1440 - r, fmod(degree, 360), yNoise ? noiseY : 0);

        if (frameCount != 0)
            ofLine(lastX, lastY, curPosX, curPosY);
    }
    //ofEndSaveScreenAsSVG();

    gui.draw();
}

//--------------------------------------------------------------
void ofApp::calculatePoint(float x, float y, float r, float graden, float posY) {
    curPosX = x + cos(ofDegToRad(graden)) * (r * 0.5);
    curPosY = y + sin(ofDegToRad(graden)) * (r * radY) + posY;
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