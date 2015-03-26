/* Copyright 2015 Jonathan Dahan <jonathan@jonathan.is>
 * Copyright 2011 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License. See LICENSE.txt for details.
 */
#pragma once

#include <ofxScenes.h>

class DotScene : public ofxScene {

  public:

    DotScene() : ofxScene("Particles") {
      alpha = 255;
      setSingleSetup(false);
    }

    void setup() {
      timer.set();

      // make some dots
      for(unsigned int i = 0; i < 200; ++i) {
        dots.push_back(ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight())));
      }
    }

    // called when scene is entering
    void updateEnter() {

      // called on first enter update
      if(isEnteringFirst()) {
        timer.setAlarm(2000);
        alpha = 0;
        ofLogNotice("DotScene") << "update enter";
      }

      // calc alpha amount based on alarm time diff
      alpha = 255*timer.getDiffN();

      update();

      // call finishedEntering() to indicate scne is done entering
      if(timer.alarm()) {
        finishedEntering();
        alpha = 255;
        ofLogNotice("DotScene") << "update enter done";
      }
    }

    void update() {
      for(ofPoint dot : dots){
        dot.x += 5*(0.5-ofRandomuf());
        dot.y += 5*(0.5-ofRandomuf());
      }
    }

    // called when scene is exiting
    void updateExit() {

      // called on first exit update
      if(isExitingFirst()) {
        timer.setAlarm(2000);
        alpha = 0;
        ofLogNotice("ParticleScene") << "update exit";
      }

      // calc alpha amount based on alarm time diff
      alpha = 255*abs(timer.getDiffN()-1.0);

      update();

      // call finishedExiting() to indicate scene is done exiting
      if(timer.alarm()) {
        finishedExiting();
        alpha = 0;
        ofLogNotice("ParticleScene") << "update exit done";
      }
    }

    void draw() {
      ofEnableAlphaBlending();
      ofFill();
      ofSetRectMode(OF_RECTMODE_CENTER);
      ofSetColor(255, 0, 0, alpha);

      for(ofPoint dot : dots){
        ofxDrawCircle(dot.x, dot.y, 5);
      }

      ofDisableAlphaBlending();
    }

    void exit() {
      dots.clear();
    }

    // used for fade in and out
    ofxTimer timer;
    int alpha;
    vector<ofPoint> dots;
};
