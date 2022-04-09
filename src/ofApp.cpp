#include "ofApp.h"
#include <cmath>

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetBackgroundAuto(false);
    ofBackground(255);
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);

    guldenSnede = ((sqrt(5) - 1) / 2);
    lastX = 0;
    lastY = 0;

    w = ofGetWidth();
    h = ofGetHeight();

    frameCount = 0;

    px = w / 2;
    py = h / 2;

    minSpeed = 3;
    maxSpeed = 40;
    minSpacing = 5;
    maxSpacing = 1024;
    minRadius = 3;
    maxRadius = 100;
    minAlpha = 50;
    maxAlpha = 200;
    minWeight = 1;
    maxWeight = 20;

    // Setup GUI
    gui.setup("panel"); // most of the time you don't need a name but don't forget to call setup

    gui.add(speed.set("speed", 0.02, minSpeed, maxSpeed));
    gui.add(spacing.set("spacing", 128, minSpacing, maxSpacing));
    //gui.add(radius.set("radius", 128, minRadius, maxRadius));
    gui.add(weight.set("weight", 1, minWeight, maxWeight));
    gui.add(bFilled.set("bFilled", false));
    gui.add(bLine.set("bLine", true));
    gui.add(bWeightNoise.set("bWeightNoise", false));
    gui.add(bRadiusNoise.set("bRadiusNoise", false));
}

//--------------------------------------------------------------
void ofApp::update() {


}

//--------------------------------------------------------------
void ofApp::draw() {    
    ofSetColor(0);
    // line weight
    //if (bWeightNoise) {
    //    weight = ofNoise(t * 0.001) * maxWeight;
    //}
    glLineWidth(weight);

    // line weight
 /*   if (bRadiusNoise) {
        radius = ofNoise(t * 0.0015) * (maxRadius - minRadius) + minRadius;
    }*/
    //string date = ofGetTimestampString("%y%m%d");
    //ofBeginSaveScreenAsSVG(date + ".svg");
    for (frameCount = 0; frameCount < 5000; frameCount++)
    {
        float t = frameCount * speed;

        lastX = px;
        lastY = py;

        degree = (t * guldenSnede) * 360;
        r = sqrt(t) * spacing;
        if (yrad < 0.5)
         yrad += 0.01;
        calculatePoint(w / 2, h / 2, 1440 - r, fmod(degree, 360));

        if (bLine && frameCount != 0)
            ofLine(lastX, lastY, px, py);
    }
    //ofEndSaveScreenAsSVG();
    //gui.draw();
}

//--------------------------------------------------------------
void ofApp::calculatePoint(float x, float y, float r, float graden) {
    px = x + cos(ofDegToRad(graden)) * (r * 0.5);
    py = y + sin(ofDegToRad(graden)) * (r * yrad);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    pause = !pause;
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