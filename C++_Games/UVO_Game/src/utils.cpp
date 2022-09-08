#include "utils.h"

////////////////////////////////////////////////////////////////////////////////
// METHODS

//// Random numbers ////
// Init random generator
void Utils::initRandomGenerator(int seed) {
	if (seed == 0) {
		srand(time(NULL));
	} else {
		srand(seed);
	}
}

// Get random integer in interval [min ; max]
int Utils::getRandom(int min, int max) {
	return rand()%(max-min+1) + min;
}

//// Conversions ////
// Number to string
string Utils::toString(int nb) {
	std::ostringstream ss;
  ss << nb;
  return ss.str();
}
string Utils::toString(double nb) {
	std::ostringstream ss;
  ss << nb;
  return ss.str();
}
string Utils::toString(bool nb) {
	std::ostringstream ss;
  ss << nb;
  return ss.str();
}

// String to string
string Utils::toLower(string str) {
	for (int i=0 ; i<str.length() ; i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}
string Utils::toUpper(string str) {
	for (int i=0 ; i<str.length() ; i++) {
		str[i] = toupper(str[i]);
	}
	return str;
}
string Utils::toFirstName(string str) {
	if (str.length() > 0) str[0] = toupper(str[0]);
	for (int i=1 ; i<str.length() ; i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}

// Number to character (0 -> A, 1 -> B, 2 -> C, ...)
string Utils::toCharacter(int nb) {
	std::ostringstream ss;
  ss << (char)(65 + nb);
  return ss.str();
}

// Character to number (A -> 0, B -> 1, C -> 2, ...)
int Utils::toNumber(char character) {
	if (character >= 65 && character < 91) {
		return character - 65;
	} else if (character >= 48 && character < 58) {
		return character - 48;
	} else if (character >= 97 && character < 123) {
		return character - 97;
	} else {
		return -1;
	}
}

//// Screen ////
// Clear screen
void Utils::clearScreen() {
	for (int i=0 ; i<100 ; i++) {
		cout << "\n";
	}
}
// Delay screen (time in ms)
void Utils::delay(int timeMs) {
	usleep((long)1000 * (long)timeMs);
}


//// Date and time ////
int Utils::todayYear() {
	time_t now = time(NULL);
	 struct tm today = *localtime(&now);
	 return today.tm_year + 1900;
}
int Utils::todayMonth() {
	time_t now = time(NULL);
	 struct tm today = *localtime(&now);
	 return today.tm_mon + 1;
}
int Utils::todayDay() {
	time_t now = time(NULL);
	 struct tm today = *localtime(&now);
	 return today.tm_mday;
}
int Utils::todayHour() {
	time_t now = time(NULL);
	 struct tm today = *localtime(&now);
	 return today.tm_hour;
}
int Utils::todayMinute() {
	time_t now = time(NULL);
	 struct tm today = *localtime(&now);
	 return today.tm_min;
}
int Utils::todaySecond() {
	time_t now = time(NULL);
	 struct tm today = *localtime(&now);
	 return today.tm_sec;
}
