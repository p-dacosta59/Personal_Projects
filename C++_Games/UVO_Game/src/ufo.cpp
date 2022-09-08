#include "ufo.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS

/*####****************** CONSTRUCTOR ******************####*/
Ufo::Ufo() {
	// Init members
	this->life = 100;
    this->alive = true;
	// Init images
    this->imageObstacle = new SfmlImage("ufo.png", 365, 124, 10.5, 3.3);
	// Display
	this->display();
    this->init(95, 100);
}

/*####****************** MOVE ******************####*/
void Ufo::moveUp() {
	if (this->y > 0) this->y -= 0.5;
}
void Ufo::moveDown() {
	if (this->y < 100) this->y += 0.1;
}
void Ufo::moveLeft() {
	if (this->x > 0) this->x -= 0.3;
}
void Ufo::moveRight() {
	if (this->x < 100) this->x += 0.3;
}

/*####****************** COLLISIONS ******************####*/
void Ufo::processCollisionWith(Obstacle* other) {
	// If collision have collision with a obstacle
	if ((*this->getImageObstacle()).overlapWith(*(other->getImageObstacle()))){
		//
        this->life -= other->getDamage();
        this->isAlive();
    }
}

/*####****************** ACCESSORS ******************####*/
void Ufo::isAlive(){
    if(this->life < 0){
        this->life = 0;
        this->alive = false;
        (this->imageObstacle)->hide();
    }
}