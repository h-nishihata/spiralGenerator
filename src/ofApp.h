// Based on:
// http://openprocessing.org/sketch/10433
// https://github.com/chimanaco/ofStudies/tree/master/019_fibonacci2D

#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void calculatePoint(float x, float y, float r, float graden);
    void clearScreen();

    ofxPanel gui;
    ofParameter<float> speed;
    ofParameter<float> spacing;
    ofParameter<float> count;
    ofParameter<float> noisePos;
    ofParameter<float> noiseCoef;
    ofxToggle noise;
    ofxButton exportAsSvg;

    int width;
    int height;
    float curPosX;
    float curPosY;

    float r;
    float degree;
    float guldenSnede;

    float lastX;
    float lastY;
    float posNoise;
    float t;

    float radY = 0.25;
};