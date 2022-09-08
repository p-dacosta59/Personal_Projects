#ifndef _OBSTACLE_H
#define _OBSTACLE_H

////////////////////////////////////////////////////////////////////////////////
// HEAD
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <math.h>
#include <unistd.h>

#include "utils.h"
#include "sfml/sfmlimage.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// CLASS
class Obstacle {

	//////////////////////////////
	// MEMBERS
	protected:
	double x;
	double y;
    double speed;
    double damage;
    bool sens;
    int lap;
    int lapChange;
	SfmlImage* imageObstacle;

	//////////////////////////////
	// PUBLIC METHODS
	public:
	/*####****************** CONSTRUCTOR ******************####*/
	Obstacle();

	/*####****************** INITIALIZER ******************####*/
	virtual void init(int yMin, int yMax);

	/*####****************** DISPLAYER ******************####*/
	virtual void display();

	/*####****************** SHIFTING ******************####*/
    virtual void shifting();
    
	/*####****************** INVERSE SHIFTING ******************####*/
    virtual void shiftingInverse();

	/*####****************** COLLISIONS ******************####*/
	virtual void processCollisionWith(Obstacle* other);

	/*####****************** ACCESOR ******************####*/
	virtual SfmlImage* getImageObstacle() const;
    
    virtual double getDamage() const;
};

#endif