/* Copyright 2015 Jonathan Dahan <jonathan@jonathan.is>
 * Copyright 2011 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License. See LICENSE.txt for details.
 */
#pragma once

#include "ofMain.h"

#include "ofxScenes.h"

// we only specify a pointer to the Particle Scene here, so tell the compiler
// that it exists as a class and we can include the class header in testApp.cpp
class ParticleScene;

/// make sure you check out main.cpp for how to run this app with app utils!
///
/// controls:
///     - L & R arrows to change scenes (note: wait for 2s transition)
///     - D arrow to change to "no scene" & U arrow to return to last scene
///     - 'd' key to toggle debug mode and enable control panel & warp editor
///     - 'm' key to mirror the render area on the x axis
///     - 'n' key to mirror the render area on the y axis
///     - 'a' key to enable aspect ratio scaling
///     - 'c' key to enable auto centering, only applied if apsect ratio scaling
///           is on and the quad warper is off
///     - 'q' key to toggle to quad warper
///     - 'f' to toggle fullscreen mode
///     - '-' & '=': remove/add particles when the particle scene is running
///
class ofApp : public ofxApp { // <-- inherits ofxApp instead of ofBaseApp
	
	public:
	
		ofApp()  {}
	
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		
		void windowResized(int w, int h);

		// handles the scenes
		ofxSceneManager sceneManager;
		int lastScene;
		
		// keep a pointer to the Particle Scene, so we can modify it more easily
		ParticleScene *particleScene;
};
