/* Copyright 2015 Jonathan Dahan <jonathan@jonathan.is>
 * Copyright (c) 2011-2012 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License. See LICENSE.txt for details.
 */
#pragma once

#include "ofxScenesApp.h"
#include "ofxTimer.h"

/**
  \class  Scene
  \brief  application scene abstract class
**/
class ofxScene :

  public ofBaseApp {

  public:

    /// the singleSetup bool controls whether the scene's setup function
    /// is called only once or each time a scene change is made
    ofxScene(std::string name, bool singleSetup=true) :
      _name(name), _bSetup(false), _bRunning(true),
      _bEntering(false), _bEnteringFirst(false),
      _bExiting(false), _bExitingFirst(false),
      _bDone(false), _bSingleSetup(singleSetup) {}
    virtual ~ofxScene() {}

  /// \section Main

    /// implement the regular ofBaseApp clalbacks functions
    /// ie setup(), update(), draw(), etc
    ///
    /// there are also the following functions for scene enter and exit
    /// control

    /// called when entering
    virtual void updateEnter() {finishedEntering();};

    /// called when exiting
    virtual void updateExit() {finishedExiting();};

  /// \section Transitional Control

    /// start entering
    inline void startEntering()     {_bEntering = true; _bEnteringFirst = true; _bDone = false;}

    /// the scene has finished entering (this should be called automatically by the scene itself)
    inline void finishedEntering()  {_bEntering = false; _bEnteringFirst = false;}

    /// is this scene currently entering?
    inline bool isEntering()        {return _bEntering;}

    /// is this scene entering for the first time?
    inline bool isEnteringFirst()   {return _bEnteringFirst;}

    /// start exiting
    inline void startExiting()      {_bExiting = true; _bExitingFirst = true;}

    /// the scene has finished exiting (this should be called automatically by the scene itself)
    inline void finishedExiting()   {_bExiting = false; _bExitingFirst = false;}

    /// is this scene currently exiting?
    inline bool isExiting()         {return _bExiting;}

    /// is this scene exiting for the first time?
    inline bool isExitingFirst()    {return _bExitingFirst;}

    /// this scene is done and wants to start exiting, note: does not start exiting
    inline void done()              {_bDone = true;}

    /// does this scene want to exit?
    inline bool isDone()            {return _bDone;}

  /// \section Util

    /// run/pause
    inline void run(bool yesno) {_bRunning = yesno;}
    inline void runToggle()     {_bRunning = !_bRunning;}

    /// get/set the scenes name
    inline void setName(std::string name)   {_name = name;}
    inline std::string getName()            {return _name;}

    /// is the scene currently running?
    inline bool isRunning() {return _bRunning;}

    /// is the scene already setup?
    inline bool isSetup()   {return _bSetup;}

    /// controls whether the scene's setup function
    /// is called only once or each time a scene change is made
    inline void setSingleSetup(bool single) {_bSingleSetup = single;}
    inline bool usingSingleSetup()          {return _bSingleSetup;}

  private:

    std::string _name; ///< the name of this scene
    bool _bSetup, _bRunning, _bEntering, _bEnteringFirst,
       _bExiting, _bExitingFirst, _bDone, _bSingleSetup;

  public:

    /// wrapper used to handle ofxScene magic behind the scenes ...
    /// do not use directly!
    class RunnerScene :

      public ofBaseApp {

      public:

        RunnerScene(ofxScene* scene);
        ~RunnerScene();

        // need these for proper entering/exit, etc
        void setup();
        void update();
        void draw();
        void exit();

        ofxScene* scene;
    };

    friend class RunnerScene; ///< used to wrap this app
};
