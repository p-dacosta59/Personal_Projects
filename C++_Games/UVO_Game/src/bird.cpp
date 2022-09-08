#include "bird.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS

/*####****************** CONSTRUCTOR ******************####*/
Bird::Bird() {
    int typeBird = Utils::getRandom(1, 4);
    switch (typeBird) {
        case 1:
            this->imageObstacle = new SfmlImage("bird1.png", 56, 39, 2.2, 1.6);
            break;
        case 2:
            this->imageObstacle = new SfmlImage("bird2.png", 37, 33, 1.5, 1.2);
            break;
        case 3:
            this->imageObstacle = new SfmlImage("bird3.png", 44, 30, 1.8, 1.2);
            break;
        case 4:
            this->imageObstacle = new SfmlImage("bird4.png", 50, 36, 2.1, 1.4);
            break;
        default:
            this->imageObstacle = new SfmlImage("bird1.png", 50, 36, 2.1, 1.4);
    }
    this->damage = 1;
    this->init(60, 80);
    this->speed = 0.1;
}