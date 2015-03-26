/* Copyright 2015 Jonathan Dahan <jonathan@jonathan.is>
 * Copyright 2011 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License. See LICENSE.txt for details.
 */
#include "ofApp.h"

#include "scenes/scenes.h"

void ofApp::setup() {

  // setup for nice jaggy-less rendering
  ofSetVerticalSync(true);
  ofBackground(0, 0, 0);

  // load scenes
  dotscene = (DotScene*) sceneManager.add(new DotScene()); // save pointer
  sceneManager.add(new LineScene());
  sceneManager.setup(true); // true = setup all the scenes now (not on the fly)
  ofSetLogLevel("ofxSceneManager", OF_LOG_VERBOSE); // lets see whats going on inside

  // start with a specific scene
  // set now to true in order to ignore the scene fade and change now
  sceneManager.gotoScene("Lines", true);
  lastScene = sceneManager.getCurrentSceneIndex();

  // attach scene manager to this ofxApp so it's called automatically,
  // you can also call the callbacks (update, draw, keyPressed, etc) manually
  // if you don't set it
  //
  // you can also turn off the auto sceneManager update and draw calls with:
  // setSceneManagerUpdate(false);
  // setSceneManagerDraw(false);
  //
  // the input callbacks in your scenes will be called if they are implemented
  //
  setSceneManager(&sceneManager);
}

void ofApp::update() {
  // the current scene are automatically updated before this function
}

void ofApp::draw() {
  // the current scene is automatically drawn before this function

  // draw current scene info using the ofxBitmapString stream interface
  // to ofDrawBitmapString
  ofSetColor(200);
  ofxBitmapString(12, ofGetHeight()-8)
    << "Current Scene: " << sceneManager.getCurrentSceneIndex()
    << " " << sceneManager.getCurrentSceneName() << endl;

}

// current scene input functions are called automatically before calling these
void ofApp::keyPressed(int key) {

  switch (key) {
    case 'd':
      bDebug = !bDebug;
      break;

    case 'f':
      ofToggleFullscreen();
      break;

    case OF_KEY_LEFT:
      sceneManager.prevScene();
      break;

    case OF_KEY_RIGHT:
      sceneManager.nextScene();
      break;

    case OF_KEY_DOWN:
      if(sceneManager.getCurrentScene()) { // returns NULL if no scene selected
        lastScene = sceneManager.getCurrentSceneIndex();
      }
      sceneManager.noScene();
      break;

    case OF_KEY_UP:
      sceneManager.gotoScene(lastScene);
      break;

    case '-':
      if(sceneManager.getCurrentScene() == dotScene) {
        dotScene->removeOneDot();
      }
      break;

    case '=':
      if(sceneManager.getCurrentScene() == dotScene) {
        dotScene->addOneDot();
      }
      break;
  }
}

void ofApp::keyReleased(int key) {
}

void ofApp::mouseMoved(int x, int y) {
}

void ofApp::mouseDragged(int x, int y, int button) {
}

void ofApp::mousePressed(int x, int y, int button) {
}

void ofApp::mouseReleased(int x, int y, int button) {
}

void ofApp::windowResized(int w, int h) {
}
