/* Copyright 2015 Jonathan Dahan <jonathan@jonathan.is>
 * Copyright 2011-2012 Dan Wilcox <danomatika@gmail.com>
 * BSD Simplified License. See license.txt for details
 */
#pragma once

#include "ofConstants.h"
#include "ofBaseApp.h"

#include "ofxTimer.h"

class ofxSceneManager;

/**
  \class  App
  \brief  application implementation with automatic transforms and projection mapping,
      includes an optional built-in ofxControlPanel

  simply inherit from this class and implement the regular app callbacks
  ie setup(), update(), draw(), etc
**/
class ofxScenesApp :

  public ofBaseApp {

  public:

    ofxScenesApp();
    virtual ~ofxScenesApp() {}

    /// set the built in SceneManager (optional)
    ///
    /// the scene manager's update, draw, and input callback functions are
    /// called automatically which, in turn, calls those of the current scene
    ///
    void setSceneManager(ofxSceneManager* manager);
    ofxSceneManager* getSceneManager();
    void clearSceneManager();

    /// enable/disable automatic scene manager update and/or draw functions
    /// (on by default)
    ///
    /// disable these in order to set your own update/draw order,
    /// simply call sceneManager.update() and/or sceneManager.draw()
    /// manually
    void setSceneManagerUpdate(bool update) {_bSceneManagerUpdate = update;}
    bool getSceneManagerUpdate()            {return _bSceneManagerUpdate;}
    void setSceneManagerDraw(bool draw)     {_bSceneManagerDraw = draw;}
    bool getSceneManagerDraw()              {return _bSceneManagerDraw;}

  private:
    ofxSceneManager* _sceneManager; ///< optional built in scene manager
    bool _bSceneManagerUpdate, _bSceneManagerDraw;

  public:

    /// wrapper used to handle ofxScenesApp magic behind the scenes ...
    /// do not use directly!
    class RunnerApp :

      public ofBaseApp {

      public:

        RunnerApp(ofxScenesApp* app);
        ~RunnerApp();

        // ofBaseApp callbacks
        void setup();
        void update();
        void draw();
        void exit();

        void keyPressed(int key);
        void keyReleased(int key);

        void mouseMoved(int x, int y);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);

        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);

        ofxScenesApp* getAppPtr() {return app;}

      private:

        ofxScenesApp* app;
    };

    friend class RunnerApp; ///< used to wrap this app
};
