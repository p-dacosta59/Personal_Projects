#include "cloud.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS

/*####****************** CONSTRUCTOR ******************####*/
Cloud::Cloud() {
    int typeCloud = Utils::getRandom(1, 4);
    switch (typeCloud) {
        case 1:
            this->imageObstacle = new SfmlImage("cloud1.png", 151, 109, 6.1, 4.1);
            break;
        case 2:
            this->imageObstacle = new SfmlImage("cloud2.png", 118, 75, 5.2, 2.9);
            break;
        case 3:
            this->imageObstacle = new SfmlImage("cloud3.png", 87, 66, 3.9, 3.1);
            break;
        case 4:
            this->imageObstacle = new SfmlImage("cloud4.png", 114, 86, 5.2, 4.3);
            break;
        default:
            break;
    }
    this->damage = 0.01;
    this->init(20, 40);
    this->speed = 0.01;
}