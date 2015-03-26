/* Copyright 2015 Jonathan Dahan <jonathan@jonathan.is>
 * Copyright (c) 2011 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License. See LICENSE.txt for details.
 */
#include "ofxScene.h"

ofxScene::RunnerScene::RunnerScene(ofxScene* scene) {
  this->scene = scene;
}

ofxScene::RunnerScene::~RunnerScene() {
  if(scene != NULL)
    delete scene;
}

void ofxScene::RunnerScene::setup() {
  if(!scene->_bSetup) {
    scene->setup();
    scene->_bSetup = true;
  }
}

void ofxScene::RunnerScene::update() {
  if(!scene->_bSetup || !scene->_bRunning)
    return;

    // update mouse pos for processing heads
    scene->mouseX = ofGetMouseX();
    scene->mouseY = ofGetMouseY();

  if(scene->_bEntering) {
    scene->updateEnter();
    scene->_bEnteringFirst = false;
  }
  else if(scene->_bExiting) {
    scene->updateExit();
    scene->_bExitingFirst = false;
  }
  else {
    scene->update();
  }
}

void ofxScene::RunnerScene::draw() {
  if(!scene->_bSetup)
    return;
  scene->draw();
}

void ofxScene::RunnerScene::exit() {
  scene->exit();
  if(!scene->_bSingleSetup) {
    scene->_bSetup = false;
  }
}
