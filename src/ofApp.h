#pragma once

#include "ofMain.h"
#include "Light.h"
#include "ofxNetwork.h"


enum StateType{
    
    STATE_IDLE,
    STATE_WARMING,
    STATE_PLAY,
    STATE_POSTPLAY,
    STATE_CRISIS
};


class ofApp : public ofBaseApp{

	public:
    
    void keyPressed(int key);
    void keyReleased(int key);
    


    void setup();
    void update();
    void draw();
    
    float warmingTime = 1;
    
    
    ofxTCPServer TCP;
    
    ofColor myTestColor;
    
    long map(long x, long in_min, long in_max, long out_min, long out_max)
    {
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }
    
    float colorLerpCounter;
    
    
    		
};
