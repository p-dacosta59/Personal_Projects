#include "sfmlsound.h"



////////////////////////////////////////////////////////////////////////////////
// METHODS

// Constructors
SfmlSound::SfmlSound() {

}
SfmlSound::SfmlSound(string soundFile) {
	this->openSound(soundFile);
}
SfmlSound::SfmlSound(string soundFile, int volume) {
	this->openSound(soundFile, volume);
}
SfmlSound::SfmlSound(string soundFile, int volume, bool isLooping) {
	this->openSound(soundFile, volume, isLooping);
}



// Open sound
void SfmlSound::openSound(string soundFile, int volume, bool isLooping) {
	// Set members
	if (0 <= volume && volume <= 100) this->volume = volume;
	else this->volume = 100;
	this->isLooping = isLooping;

	// Open sound
	this->soundBuffer.loadFromFile("./src/ressources/sounds/" + soundFile);
	this->sound.setBuffer(this->soundBuffer);
	this->sound.setVolume(this->volume);
	this->sound.setLoop(this->isLooping);
}



// Controls
void SfmlSound::play() {
	this->sound.play();
}
void SfmlSound::pause() {
	this->sound.pause();
}
void SfmlSound::stop() {
	this->sound.stop();
}
void SfmlSound::setVolume(int volume) {
	if (0 <= volume && volume <= 100) this->volume = volume;
	else this->volume = 100;
	this->sound.setVolume(this->volume);
}
void SfmlSound::increaseVolume(int volume) {
	this->volume += volume;
	if (this->volume > 100) this->volume = 100;
	this->sound.setVolume(this->volume);
}
void SfmlSound::decreaseVolume(int volume) {
	this->volume -= volume;
	if (this->volume < 0) this->volume = 0;
	this->sound.setVolume(this->volume);
}
void SfmlSound::setLoop(bool isLooping) {
	this->isLooping = isLooping;
	this->sound.setLoop(this->isLooping);
}










////////////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS
