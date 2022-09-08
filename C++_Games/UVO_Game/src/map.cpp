#include "map.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS

/*####****************** CONSTRUCTOR ******************####*/
Map::Map(Sfml* window) {
	// Create players
    this->player = new Ufo;
    this->elements[0] = this->player;

	// Create obstacles
	for (int i=0; i<15; i++) {
		this->elements[i+1] = new Cloud;
	}
    this->elements[16] = new Plane;
    for (int i=0; i<20; i++) {
        this->elements[i+17] = new Bird;
    }
    for (int i=0; i<4; i++) {
        this->elements[i+37] = new StormCloud;
    }
	// Add element images to window
	for (int i=0 ; i<NB_ELEMENT ; i++) {
		(*window).addImage(*(this->elements[i])->getImageObstacle());
	}
}

/*####****************** DISPLAYER ******************####*/
void Map::display() {
	for (int i=0 ; i<NB_ELEMENT; i++) {
		(this->elements[i])->display();
	}

}

/*####****************** DO ONE STEP ******************####*/
void Map::doOneStep() {
	// For each pair of element
	for (int i=1 ; i<NB_ELEMENT ; i++) {
        (this->player)->processCollisionWith(this->elements[i]);
	}
    
}

/*####****************** ACCESSORS ******************####*/
Ufo* Map::getPlayer() {
	return this->player;
}