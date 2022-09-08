#ifndef _BIRD_H
#define _BIRD_H

////////////////////////////////////////////////////////////////////////////////
// HEAD
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <math.h>
#include <unistd.h>

#include "obstacle.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// CLASS
class Bird : public Obstacle {
	//////////////////////////////
	// PUBLIC METHODS
	public:
	/*####****************** CONSTRUCTOR ******************####*/
	Bird();
};

#endif