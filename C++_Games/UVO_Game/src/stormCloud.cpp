#include "stormCloud.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS

/*####****************** CONSTRUCTOR ******************####*/
StormCloud::StormCloud() {
    int typeStormCloud = Utils::getRandom(1, 2);
    switch (typeStormCloud) {
        case 1:
            this->imageObstacle = new SfmlImage("stormcloud1.png", 214, 217, 9.1, 9.2);
            break;
        case 2:
            this->imageObstacle = new SfmlImage("stormcloud2.png", 187, 353, 7.5, 14.6);
            break;
        default:
            this->imageObstacle = new SfmlImage("stormcloud2.png", 187, 353, 7.5, 14.6);
            break;
    }
    this->damage = 0.3;
    this->init(80, 100);
    this->speed = 0.005;
}