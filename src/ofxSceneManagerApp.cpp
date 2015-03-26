/*
 * Copyright 2015 Jonathan Dahan <jonathan@jonathan.is>
 * Copyright 2011-2012 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License. See LICENSE.txt for details
 */
#include "ofxScenesApp.h"

#include "ofGraphics.h"
#include "ofAppRunner.h"

#include "ofxSceneManager.h"

ofxScenesApp::ofxScenesApp() {
  _sceneManager = NULL;
  _bSceneManagerUpdate = true;
  _bSceneManagerDraw = true;
}

void ofxScenesApp::setSceneManager(ofxSceneManager* manager) {
  if(manager == NULL) {
    ofLogWarning("ofxScenesApp") << "cannot add NULL scene manager";
    return;
  }
  _sceneManager = manager;
}

ofxSceneManager* ofxScenesApp::getSceneManager() {
  return _sceneManager;
}

void ofxScenesApp::clearSceneManager() {
  _sceneManager = NULL;
}

ofxScenesApp::RunnerApp::RunnerApp(ofxScenesApp* app) {
  this->app = app;
}

ofxScenesApp::RunnerApp::~RunnerApp() {
  delete app;
}

void ofxScenesApp::RunnerApp::setup() {
  app->setup();
}

void ofxScenesApp::RunnerApp::update() {
  app->mouseX = mouseX;
  app->mouseY = mouseY;

  if(app->_sceneManager && app->_bSceneManagerUpdate)
    app->_sceneManager->update();
  app->update();
}

void ofxScenesApp::RunnerApp::draw() {
  if(app->_sceneManager && app->_bSceneManagerDraw)
    app->_sceneManager->draw();

  // do the user callback
  app->draw();
}

void ofxScenesApp::RunnerApp::exit() {
  app->exit();
  if(app->_sceneManager)
    app->_sceneManager->clear();
}

void ofxScenesApp::RunnerApp::keyPressed(int key) {
  if(app->_sceneManager)
    app->_sceneManager->keyPressed(key);
  app->keyPressed(key);
}

void ofxScenesApp::RunnerApp::keyReleased(int key) {
  if(app->_sceneManager)
    app->_sceneManager->keyReleased(key);
  app->keyReleased(key);
}

void ofxScenesApp::RunnerApp::mouseMoved(int x, int y) {
  if(app->_sceneManager)
    app->_sceneManager->mouseMoved(x, y);
  app->mouseMoved(x, y);
}

void ofxScenesApp::RunnerApp::mouseDragged(int x, int y, int button) {
  if(app->_sceneManager)
    app->_sceneManager->mouseDragged(x, y, button);
  app->mouseDragged(x, y, button);
}

void ofxScenesApp::RunnerApp::mousePressed(int x, int y, int button) {
  if(app->_sceneManager)
    app->_sceneManager->mousePressed(x, y, button);
  app->mousePressed(x, y, button);
}

void ofxScenesApp::RunnerApp::mouseReleased(int x, int y, int button) {
  if(app->_sceneManager)
    app->_sceneManager->mouseReleased(x, y, button);
  app->mouseReleased(x, y, button);
}

void ofxScenesApp::RunnerApp::windowResized(int w, int h) {
  if(app->_sceneManager)
    app->_sceneManager->windowResized(w, h);
  app->windowResized(w, h);
}

void ofxScenesApp::RunnerApp::dragEvent(ofDragInfo dragInfo) {
  if(app->_sceneManager)
    app->_sceneManager->dragEvent(dragInfo);
  app->dragEvent(dragInfo);
}

void ofxScenesApp::RunnerApp::gotMessage(ofMessage msg){
  if(app->_sceneManager)
    app->_sceneManager->gotMessage(msg);
  app->gotMessage(msg);
}
