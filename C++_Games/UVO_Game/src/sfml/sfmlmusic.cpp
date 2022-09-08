#include "sfmlmusic.h"



////////////////////////////////////////////////////////////////////////////////
// METHODS

// Constructors
SfmlMusic::SfmlMusic() {

}
SfmlMusic::SfmlMusic(string musicFile) {
	this->openMusic(musicFile);
}
SfmlMusic::SfmlMusic(string musicFile, int volume) {
	this->openMusic(musicFile, volume);
}
SfmlMusic::SfmlMusic(string musicFile, int volume, bool isLooping) {
	this->openMusic(musicFile, volume, isLooping);
}



// Open music
void SfmlMusic::openMusic(string musicFile, int volume, bool isLooping) {
	// Set members
	if (0 <= volume && volume <= 100) this->volume = volume;
	else this->volume = 100;
	this->isLooping = isLooping;

	// Open music
	this->music.openFromFile("./src/ressources/music/" + musicFile);
	this->music.setVolume(this->volume);
	this->music.setLoop(this->isLooping);
	this->music.play();
}



// Controls
void SfmlMusic::play() {
	this->music.play();
}
void SfmlMusic::pause() {
	this->music.pause();
}
void SfmlMusic::stop() {
	this->music.stop();
}
void SfmlMusic::setVolume(int volume) {
	if (0 <= volume && volume <= 100) this->volume = volume;
	else this->volume = 100;
	this->music.setVolume(this->volume);
}
void SfmlMusic::increaseVolume(int volume) {
	this->volume += volume;
	if (this->volume > 100) this->volume = 100;
	this->music.setVolume(this->volume);
}
void SfmlMusic::decreaseVolume(int volume) {
	this->volume -= volume;
	if (this->volume < 0) this->volume = 0;
	this->music.setVolume(this->volume);
}
void SfmlMusic::setLoop(bool isLooping) {
	this->isLooping = isLooping;
	this->music.setLoop(this->isLooping);
}










////////////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS
