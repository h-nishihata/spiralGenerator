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
    void clearScreen();
    void calculatePoint(float x, float y, float r, float graden, float posY);

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofxPanel gui;
    ofParameter<float> speed;
    ofParameter<float> spacing;
    ofParameter<float> radius;
    ofParameter<float> weight;

    int width;
    int height;
    float centerX;
    float centerY;

    float r;
    float degree;
    float guldenSnede;

    float lastX;
    float lastY;

    float minSpeed;
    float maxSpeed;
    float minSpacing;
    float maxSpacing;

    float yrad = 0.25;
};