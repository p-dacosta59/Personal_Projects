#ifndef _MAP_H
#define _MAP_H

////////////////////////////////////////////////////////////////////////////////
// HEAD
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <math.h>
#include <unistd.h>

#include "sfml/sfml.h"
#include "obstacle.h"
#include "cloud.h"
#include "ufo.h"
#include "plane.h"
#include "bird.h"
#include "stormCloud.h"

using namespace std;

#define NB_ELEMENT 41

////////////////////////////////////////////////////////////////////////////////
// CLASS
class Map {

	//////////////////////////////
	// MEMBERS
	private:
	Ufo* player;
	Obstacle* elements[NB_ELEMENT];

	//////////////////////////////
	// PUBLIC METHODS
	public:
	/*####****************** CONSTRUCTOR ******************####*/
	Map(Sfml* window);

	/*####****************** DISPLAYER ******************####*/
	void display();

	/*####****************** DO ONE STEP ******************####*/
	void doOneStep();

	/*####****************** ACCESSORS ******************####*/
	Ufo* getPlayer();
};

#endif