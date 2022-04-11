#include "ofApp.h"
#include <cmath>
//--------------------------------------------------------------
void ofApp::setup() {
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
    gui.add(speed.set("Speed", 0.02, 0, 0.1));
    gui.add(spacing.set("Spacing", 128, 8, 1024));
    gui.add(count.set("Count", 5000, 512, 12000));
    gui.add(noisePos.set("NoisePos", 2500, 0, 5000));
    gui.add(noiseCoef.set("NoiseCoef", 0.03, -0.1, 0.1));
    gui.add(noise.setup("Noise", false));
    gui.add(exportAsSvg.setup("Export"));
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    clearScreen();
    ofSetColor(0);
    glLineWidth(1);

    if (exportAsSvg)
    {
        string date = ofGetTimestampString("%y%m%d");
        ofBeginSaveScreenAsSVG(date + ".svg");
    }

    for (int frameCount = 0; frameCount < count; frameCount++)
    {
        t = frameCount * speed;
        posNoise = noise ? (frameCount - noisePos) * noiseCoef : 0;

        lastX = curPosX;
        lastY = curPosY;

        degree = (t * guldenSnede) * 360;
        
        r = sqrt(t) * spacing;
        radY = ofMap(frameCount, 0, 5000, 0.5, 0.2);
        calculatePoint(width * 0.5, height * 0.5, 1440 - r, fmod(degree, 360));

        if (frameCount != 0)
            ofLine(lastX, lastY, curPosX, curPosY);
    }
    if (exportAsSvg)
        ofEndSaveScreenAsSVG();

    gui.draw();
}

//--------------------------------------------------------------
void ofApp::calculatePoint(float x, float y, float r, float graden) {
    curPosX = x + cos(ofDegToRad(graden)) * (r * 0.5) + posNoise;
    curPosY = y + sin(ofDegToRad(graden)) * (r * radY) + posNoise;
}

//--------------------------------------------------------------
void ofApp::clearScreen() {
    ofSetColor(255);
    ofFill();
    ofRect(0, 0, width, height);
}