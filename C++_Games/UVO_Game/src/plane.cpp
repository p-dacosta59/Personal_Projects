#include "plane.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS

/*####****************** CONSTRUCTOR ******************####*/
Plane::Plane() {
    this->imageObstacle = new SfmlImage("plane.png", 353, 264, 14.3, 11.2);
    this->damage = 100;
    this->init(40, 60);
    this->speed = 1;
}