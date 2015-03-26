/* Copyright 2015 Jonathan Dahan <jonathan@jonathan.is>
 * Copyright 2011-2012 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License. See LICENSE.txt for details.
 */
#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGlutWindow.h"

int main(){
  ofAppGlutWindow window;
  ofSetupOpenGL(&window, 800, 600, OF_WINDOW);

  // this replaces ofRunApp() and kicks off the running of the app
  ofRunScenesApp(new ofApp());
}
