#ifndef _UFO_H
#define _UFO_H

////////////////////////////////////////////////////////////////////////////////
// HEAD
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <math.h>
#include <unistd.h>

#include "sfml/sfmlimage.h"
#include "obstacle.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// CLASS
class Ufo : public Obstacle {

	//////////////////////////////
	// MEMBERS
	private:
	int life;
    bool alive;

	//////////////////////////////
	// PUBLIC METHODS
	public:
	/*####****************** CONSTRUCTOR ******************####*/
	Ufo();

	/*####****************** MOVE ******************####*/
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	/*####****************** COLLISIONS ******************####*/
	virtual void processCollisionWith(Obstacle* other);

	/*####****************** ACCESSORS ******************####*/
    void isAlive();
};

#endif