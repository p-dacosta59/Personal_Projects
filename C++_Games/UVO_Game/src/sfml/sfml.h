#ifndef _SFML_H
#define _SFML_H



////////////////////////////////////////////////////////////////////////////////
// HEAD
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "sfmlimage.h"
using namespace std;



////////////////////////////////////////////////////////////////////////////////
// CLASS
class Sfml {

	//////////////////////////////
	// MEMBERS
	private:
	// Window
	string windowName;
	int windowX;
	int windowY;
	bool cursorVisible;
	bool windowOpen;
	double vw;
	double vh;
	sf::RenderWindow* window;

	// Images
	vector<SfmlImage*> images;



	//////////////////////////////
	// PUBLIC METHODS
	public:
	Sfml();
	Sfml(string windowName);
	Sfml(string windowName, int windowX, int windowY);
	Sfml(string windowName, int windowX, int windowY, bool cursorVisible);

	// Window open
	bool isOpen();

	// Close window
	void close();

	// Add/remove image
	void addImage(SfmlImage& image);
	void removeImage(SfmlImage& image);

	// Show/hide images
	void showAll();
	void hideAll();

	// Display
	void display();

	// Catch event (required)
	bool catchEvent();
	void catchEvents();																														// Catch all events (uncontrolled key repetitions) (avoid while loop in main prgm)



	//////////////////////////////
	// PRIVATE METHODS
	private:

	// Open window
	void openWindow(string windowName="", int windowX=1024, int windowY=768, bool cursorVisible=true);

	// Draw images
	void drawImages();
	void drawImage(SfmlImage* image);

};


#endif
