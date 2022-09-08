#ifndef _SFMLIMAGE_H
#define _SFMLIMAGE_H



////////////////////////////////////////////////////////////////////////////////
// HEAD
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>
using namespace std;



////////////////////////////////////////////////////////////////////////////////
// CLASS
class SfmlImage {

	//////////////////////////////
	// MEMBERS
	public:
		int originalSizeX;
		int originalSizeY;
		double sizeX;
		double sizeY;
		double posX;
		double posY;
		double rotation;
		bool isVisible;
		sf::Texture texture;
		sf::Sprite sprite;



	//////////////////////////////
	// PUBLIC METHODS
	public:
	SfmlImage();
	SfmlImage(string imageFile);
	SfmlImage(string imageFile, int originalSizeX, int originalSizeY);
	SfmlImage(string imageFile, int originalSizeX, int originalSizeY, double sizeX, double sizeY);

	// Open image
	void openImage(string imageFile, int originalSizeX=100, int originalSizeY=0, double sizeX=5.0, double sizeY=0.0);

	// Detect overlapping
	bool overlapWith(SfmlImage& image);

	// Mutators : size, position, rotation, visible
	void setSize(double sizeX, double sizeY=0.0);
	void setPosition(double posX, double posY);
	void setPositionX(double posX);
	void setPositionY(double posY);
	void changePositionBy(double posX, double posY);
	void changePositionXBy(double posX);
	void changePositionYBy(double posY);
	void setRotation(double rotation);
	void changeRotationBy(double rotation);
	void show();
	void hide();



	//////////////////////////////
	// PRIVATE METHODS
	private:


};


#endif
