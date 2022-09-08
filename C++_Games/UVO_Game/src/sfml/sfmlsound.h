#ifndef _SFMLSOUND_H
#define _SFMLSOUND_H



////////////////////////////////////////////////////////////////////////////////
// HEAD
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <SFML/Audio.hpp>
using namespace std;



////////////////////////////////////////////////////////////////////////////////
// CLASS
class SfmlSound {

	//////////////////////////////
	// MEMBERS
	public:
	bool isLooping;
	int volume;
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;



	//////////////////////////////
	// PUBLIC METHODS
	public:
	SfmlSound();
	SfmlSound(string soundFile);
	SfmlSound(string soundFile, int volume);
	SfmlSound(string soundFile, int volume, bool isLooping);

	// Open sound
	void openSound(string soundFile, int volume=100, bool isLooping=false);

	// Controls
	void play();
	void pause();
	void stop();
	void setVolume(int volume=100);
	void increaseVolume(int volume=5);
	void decreaseVolume(int volume=5);
	void setLoop(bool isLooping=true);



	//////////////////////////////
	// PRIVATE METHODS

};


#endif
