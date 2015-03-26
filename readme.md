ofxScenes
=========

Simple scene manager extracted from [Dan Wilcox](danomatika.com)'s [ofxAppUtils](https://github.com/danomatika/ofxAppUtils)

Create a bunch of scenes, and link them together using a `std::map`

ofxScenesApp will handle individual scene's `setup`, `update`, and `draw`, as well as all ofBaseApp callbacks

Many thanks to him for doing all the hard work. All I did was remove as much as I could
for barebones scene management. No quad warping, no gui, no iOS, no audio events handling.

Installation
------------

You can either download the zip from [http://github.com/jedahan/ofxSceneManager/zipball/master](http://github.com/jedahan/ofxSceneManager/zipball/master), or (recommended) clone the git repository to make it easier to update:

    cd ${HOME}/openFrameworks/addons
    git clone git://github.com/jedahan/ofxSceneManger.git .


Running the Example Project
---------------------------

The example project is in the `examples` folder.

Project files for the examples are not included so you will need to generate the project files for your operating system and development environment using the OF ProjectGenerator which is included with the OpenFrameworks distribution.

Point the ProjectGenerator to `addons/ofxScenes`, change the project name to the **exact** name of the example you want to generate (ie `lineAndDots`), and make sure to choose `ofxScenes` from the addons. Hitting "Generate Project" will populate that example with the project files you will need to build it.


Adding ofxScenes to an Existing Project
---------------------------------------

### ProjectGenerator

Select ofxScenes and other addons used by your project from the available addons in the ProjectGenerator, select the parent folder of your project, and set the *exact* name of the existing project in the text box. This will overwrite the existing project files with new ones that now include ofxScenes.

*Note: you will lose any custom settings you've added manually to your project.*

### Manual Method for OSX or Linux

    touch addons.make
    echo ofxScenes >> addons.make

### Manual Method for XCode

I totally recommend using [admsyn](https://github.com/admsyn)'s [OFPlugin](https://github.com/admsyn/OFPlugin) to add plugins after the fact in Xcode.


### Extending Your BaseApp

There are two changes you need to make to extend your app with the ofScenes ofxScenesApp class which handles all the *automagic*:

* your base app needs to inherit from `ofxScenesApp`, so in **src/ofApp.cpp**

    class ofApp : public ofBaseApp {

becomes

    class ofApp : public ofxScenesApp {

* your app needs to be launched with `ofRunAppWithScenes` in **src/main.cpp**

    ofRunApp(new ofApp());

becomes

    ofRunAppWithScenes(new ofApp());

That's it. Check the example ofApp::setup() for more info on startup settings.

#### ofxGetAppPtr

Internally, calling `ofRunAppWithScenes` actually creates a wrapper ofBaseApp which then runs the given ofxScenesApp. As a result, **calling `ofGetAppPtr()` does not work correctly** as it returns a pointer to the wrapper and not the app itself.

In order to fix this, there is a new function added with ofxScenes called `ofxGetAppPtr()` (note the "x") which returns the correct pointer. If you are porting existing code, make sure to change any `ofGetAppPtr()` calls to `ofxGetAppPtr()`.

