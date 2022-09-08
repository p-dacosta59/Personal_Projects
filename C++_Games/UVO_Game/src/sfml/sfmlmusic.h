#ifndef _SFMLMUSIC_H
#define _SFMLMUSIC_H



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
class SfmlMusic {

	//////////////////////////////
	// MEMBERS
	public:
	bool isLooping;
	int volume;
	sf::Music music;



	//////////////////////////////
	// PUBLIC METHODS
	public:
	SfmlMusic();
	SfmlMusic(string musicFile);
	SfmlMusic(string musicFile, int volume);
	SfmlMusic(string musicFile, int volume, bool isLooping);

	// Open music
	void openMusic(string musicFile, int volume=100, bool isLooping=true);

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
