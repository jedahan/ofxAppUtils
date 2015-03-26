/* Copyright 2015 Jonathan Dahan <jonathan@jonathan.is>
 * Copyright (c) 2011 Dan Wilcox <danomatika@gmail.com>
 * BSD Simplified License. See license.txt for details.
 */
#pragma once

#include "ofAppRunner.h"

#include "ofxScenes.h"
#include "ofxSceneManager.h"
#include "ofxScenesApp.h"

/// replace ofRunApp with this in main.cpp
inline void ofRunScenesApp(ofxScenesApp* app) {
  ofRunApp((ofBaseApp*) new ofxScenesApp::RunnerApp(app));
}

inline ofxScenesApp* ofxGetAppPtr() {
  return ((ofxScenesApp::RunnerApp*) ofGetAppPtr())->getAppPtr();
}
