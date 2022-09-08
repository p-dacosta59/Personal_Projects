////////////////////////////////////////////////////////////////////////////////
// HEAD
#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>
#include <math.h>
#include <unistd.h>

#include "utils.h"
#include "sfml/sfml.h"
#include "sfml/sfmlimage.h"
#include "sfml/sfmlmusic.h"
#include "map.h"
#include "obstacle.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// BODY
int main() {
	// Begin
	cout << "[BEGIN]-------------------------------------------\n";

	// Init random generator
	Utils::initRandomGenerator();

	// DECL
	Sfml window("UFO", 1000, 1000, true);

	//SfmlMusic ambiantMusic("soixante8.ogg", 10, true);
	Map map(&window);

	// Loop
	while (window.isOpen()) {
		// Handle events
		while (window.catchEvent()) {
			//  Move Ovni
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) (*map.getPlayer()).moveUp();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) (*map.getPlayer()).moveDown();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) (*map.getPlayer()).moveLeft();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) (*map.getPlayer()).moveRight();
        }
        if (!((sf::Keyboard::isKeyPressed(sf::Keyboard::E)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::F)))){
            (*map.getPlayer()).moveDown();
        }
		// Display
		map.display();
		window.display();
		Utils::delay(10);
        // Do one step
        map.doOneStep();
	}
	// Display scores
	Utils::clearScreen();

	cout << "[END]---------------------------------------------\n";
	return 0;
}