#pragma once

#include "ofMain.h"
#include "Light.h"
#include "ofxNetwork.h"
#include "Cube.h"





class ofApp : public ofBaseApp{

	public:
    
    void keyPressed(int key);
    void keyReleased(int key);
    
    

    void setup();
    void update();
    void draw();
    void exit();

    
    float warmingTime = 1;
    
    
    ofxTCPServer TCP;
    
    ofColor myTestColor;
    
    long map(long x, long in_min, long in_max, long out_min, long out_max)
    {
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }
    
    float colorLerpCounter;
    
    int swingsTempo[5][1];
    
    void setIntensityCube();
    
    vector<Cube> cubes;

    
    		
};
