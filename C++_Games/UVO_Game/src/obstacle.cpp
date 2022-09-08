#include "obstacle.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS

/*####****************** CONSTRUCTOR ******************####*/
Obstacle::Obstacle() {

}

/*####****************** INITIALIZER ******************####*/
void Obstacle::init(int yMin, int yMax) {
    //Position in X
    this->x = Utils::getRandom(0, 100);
    //Position in Y
    this->y = Utils::getRandom(yMin, yMax);
    //
    (this->imageObstacle)->show();
    this->lap = 0;
}

/*####****************** DISPLAYER ******************####*/
void Obstacle::display() {
    // Set images position
    if(sens) this->shiftingInverse();
    else this->shifting();
    (this->imageObstacle)->setPosition(this->x, this->y);
    
    if(lap == 0) this->lapChange = Utils::getRandom(1, 500);
    if(lap == lapChange || lap == 2000){
        sens = !sens;
        this->lap = 0;
    }else lap ++;
}

/*####****************** SHIFTING ******************####*/
void Obstacle::shifting(){
    if (this->x > 0) {
        this->x -= this->speed;
    }else{
        this->x = 0;
    }
}

/*####****************** INVERSE SHIFTING ******************####*/
void Obstacle::shiftingInverse(){
    if (this->x < 100) {
        this->x += this->speed;
    }else{
        this->x = 100;
    }
}

/*####****************** COLLISIONS ******************####*/
void Obstacle::processCollisionWith(Obstacle* other) {

}

/*####****************** ACCESOR ******************####*/
SfmlImage* Obstacle::getImageObstacle() const{
	return this->imageObstacle;
}
double Obstacle::getDamage() const{
    return this->damage;
}