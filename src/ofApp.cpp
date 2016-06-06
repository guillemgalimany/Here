#include "ofApp.h"
#include "ofxNetwork.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
    

    ofHideCursor();
    
    Light::getInstance().initialize();      // Els pars es posen tots a tope
    //Light::getInstance().fadePars(1, 'O', '0', warmingTime, 3);
    
    TCP.setup(8080);


}

//--------------------------------------------------------------
void ofApp::update(){

    // LIGHT
    Light::getInstance().getInfo();
    
    //ofColor myPrevColor = myTestColor;

    
    // TCP
    for(int i = 0; i < TCP.getLastID(); i++) // getLastID is UID of all clients
    {
        
        if( TCP.isClientConnected(i) ) { // check and see if it's still around
            // maybe the client is sending something
            std::string str = TCP.receive(i);
            //cout << str;
            if (str != "")
            {
                std::vector<int> vect;
                
                std::stringstream ss(str);
                
                int i;
                
                while (ss >> i)
                {
                    vect.push_back(i);
                    
                    if (ss.peek() == ',')
                        ss.ignore();
                }
                
        //            for (i=0; i< vect.size(); i++)
        //                std::cout << vect.at(i)<<std::endl;
                
//                float intensity = map(vect.at(3),200,12000,0,255);
//                
//                cout << vect.at(3)<<std::endl;
//                cout << intensity<<std::endl;
//                
//                myTestColor.set(0,0,intensity);
//                
//                colorLerpCounter = 0;
//                
//                ofResetElapsedTimeCounter();
                
                int tempo = vect.at(2);
                
                switch (tempo) {
                    case 0:
                        //Light::getInstance().setParsColor(0);
                        
                        Light::getInstance().fade(0, ofColor(0,0,0), 1);
                        
                        break;
                    case 1:
                        //Light::getInstance().setParsColor(50);
                        
                        Light::getInstance().fade(0, ofColor(0,0,100), 1);
                        
                        break;
                    case 2:
                        //Light::getInstance().setParsColor(150);
                        
                        Light::getInstance().fade(0, ofColor(0,0,170), 1);

                        break;
                    case 3:
                        //Light::getInstance().setParsColor(255);
                        
                        Light::getInstance().fade(0, ofColor(0,0,255), 1);

                        break;
                        
                    default:
                        break;
                }

            }
            //ofLog(OF_LOG_NOTICE ,str);
            //TCP.send(i, "You sent: "+str);
        }
    }
    

    //myPrevColor.lerp(myTestColor,ofGetElapsedTimef());
    
    //Light::getInstance().setParsColor(myPrevColor);

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch(key)
    {
        case 'f':
            Light::getInstance().setParsColor(ofColor(255,0,0));
            break;
        case 'j':
            Light::getInstance().setParsColor(ofColor(0,255,0));

            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    switch(key)
    {
        case 'f':
            break;
        case 'j':
            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw()
{

}
