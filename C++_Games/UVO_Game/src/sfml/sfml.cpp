#include "sfml.h"



////////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS

// Constructors
Sfml::Sfml() {
	this->openWindow();
}
Sfml::Sfml(string windowName) {
	this->openWindow(windowName);
}
Sfml::Sfml(string windowName, int windowX, int windowY) {
	this->openWindow(windowName, windowX, windowY);
}
Sfml::Sfml(string windowName, int windowX, int windowY, bool cursorVisible) {
	this->openWindow(windowName, windowX, windowY, cursorVisible);
}



// Window open
bool Sfml::isOpen() {
	return this->windowOpen && this->window->isOpen();
}



// Close window
void Sfml::close() {
	// If window open
	if (this->windowOpen) {
		this->windowOpen = false;
		this->window->close();
	}
}



// Add/remove image
void Sfml::addImage(SfmlImage& image) {
	this->images.push_back(&image);
}
void Sfml::removeImage(SfmlImage& image) {
	for (auto it = this->images.begin(); it != this->images.end(); ) {
		if (*it == &image) {
			it = this->images.erase(it);
		} else {
			it++;
		}
	}
}



// Show/hide images
void Sfml::showAll() {
	for (auto e : this->images) {
		e->show();
	}
}
void Sfml::hideAll() {
	for (auto e : this->images) {
		e->hide();
	}
}



// Display
void Sfml::display() {
	// Clear
	this->window->clear(sf::Color::White);

	// Draw images
	this->drawImages();

	// Display
	this->window->display();
}


// Catch event (required)
bool Sfml::catchEvent() {
	// Catch next event
	sf::Event event;
	if (this->window->pollEvent(event)) {
		// Close event
		if (event.type == sf::Event::Closed) this->close();

		return true;
	}
	return false;
}
void Sfml::catchEvents() {
	// Catch next event
	sf::Event event;
	while (this->window->pollEvent(event)) {
		// Close event
		if (event.type == sf::Event::Closed) this->close();
	}
}










////////////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS



// Open window
void Sfml::openWindow(string windowName, int windowX, int windowY, bool cursorVisible) {
	// If window not open
	if (!this->windowOpen) {
		// Set members
		this->windowName = windowName;
		this->windowX = windowX;
		this->windowY = windowY;
		this->cursorVisible = cursorVisible;
		this->windowOpen = true;

		// Create window
		this->window = new sf::RenderWindow(sf::VideoMode(this->windowX, this->windowY), this->windowName);

		// Update vw and vh
		this->vw = this->windowX / 100.0;
		this->vh = this->windowY / 100.0;
		// this->vw = this->window->getSize().x / 100.0;
		// this->vh = this->window->getSize().y / 100.0;

		// Hide/show cursor
		window->setMouseCursorVisible(this->cursorVisible);
	}
}



// Draw images
void Sfml::drawImages() {
	// Draw images
	for (auto& elt : this->images) {
		this->drawImage(elt);
	}
}
void Sfml::drawImage(SfmlImage* image) {
	image->sprite.setScale(image->sizeX * this->vw / image->originalSizeX, image->sizeY * this->vh / image->originalSizeY);
	image->sprite.setPosition(image->posX * this->vw, image->posY * this->vh);
	image->sprite.setRotation(image->rotation);
	if (image->isVisible) this->window->draw(image->sprite);
}
