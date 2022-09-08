#include "sfmlimage.h"



////////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS

// Constructors
SfmlImage::SfmlImage() {

}
SfmlImage::SfmlImage(string imageFile) {
	this->openImage(imageFile);
}
SfmlImage::SfmlImage(string imageFile, int originalSizeX, int originalSizeY) {
	this->openImage(imageFile, originalSizeX, originalSizeY);
}
SfmlImage::SfmlImage(string imageFile, int originalSizeX, int originalSizeY, double sizeX, double sizeY) {
	this->openImage(imageFile, originalSizeX, originalSizeY, sizeX, sizeY);
}



// Open image
void SfmlImage::openImage(string imageFile, int originalSizeX, int originalSizeY, double sizeX, double sizeY) {
	// Set members
	this->originalSizeX = originalSizeX;
	if (originalSizeY == 0) this->originalSizeY = this->originalSizeX;
	else this->originalSizeY = originalSizeY;
	this->sizeX = sizeX;
	if (sizeY == 0.0) this->sizeY = this->sizeX;
	else this->sizeY = sizeY;
	this->posX = 0;
	this->posY = 0;
	this->rotation = 0;
	this->isVisible = true;

	// Load texture
	this->texture.loadFromFile("./src/ressources/images/" + imageFile);

	// Create sprite
	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(this->originalSizeX / 2, this->originalSizeY / 2);
}



// Detect overlapping
bool SfmlImage::overlapWith(SfmlImage& image) {
	if (abs(this->posX - image.posX) < (this->sizeX / 2.0 + image.sizeX / 2.0) && abs(this->posY - image.posY) < (this->sizeY / 2.0 + image.sizeY / 2.0) && this->isVisible && image.isVisible) return true;
	else return false;
}



// Mutators size, position, rotation, visible
void SfmlImage::setSize(double sizeX, double sizeY) {
	this->sizeX = sizeX;
	if (sizeY == 0.0) this->sizeY = this->sizeX;
	else this->sizeY = sizeY;
}
void SfmlImage::setPosition(double posX, double posY) {
	this->setPositionX(posX);
	this->setPositionY(posY);
}
void SfmlImage::setPositionX(double posX) {
	this->posX = posX;
}
void SfmlImage::setPositionY(double posY) {
	this->posY = posY;
}
void SfmlImage::changePositionBy(double posX, double posY) {
	this->changePositionXBy(posX);
	this->changePositionYBy(posY);
}
void SfmlImage::changePositionXBy(double posX) {
	this->posX += posX;
}
void SfmlImage::changePositionYBy(double posY) {
	this->posY += posY;
}
void SfmlImage::setRotation(double rotation) {
	while(rotation > 180) rotation -= 360;
	while(rotation < -180) rotation += 360;
	this->rotation = rotation;

}
void SfmlImage::changeRotationBy(double rotation) {
	while(this->rotation + rotation > 180) rotation -= 360;
	while(this->rotation + rotation < -180) rotation += 360;
	this->rotation = this->rotation + rotation;
}
void SfmlImage::show() {
	this->isVisible = true;
}
void SfmlImage::hide() {
	this->isVisible = false;
}










////////////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS
