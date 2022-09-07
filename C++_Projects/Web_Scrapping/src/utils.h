#ifndef _UTILS_H
#define _UTILS_H
////////////////////////////////////////////////////////////////////////////////
// HEAD
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <math.h>
#include <unistd.h>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// CLASS
class Utils {

	//////////////////////////////
	// METHODS
	public:

	//// Random numbers ////
	// Init random generator
	static void initRandomGenerator(int seed=0);

	// Get random integer in interval [min ; max]
	static int getRandom(int min=0, int max=100);

	//// Conversions ////
	// Number to string
	static string toString(int nb);
	static string toString(double nb);
	static string toString(bool nb);

	// String to string
	static string toLower(string str);
	static string toUpper(string str);
	static string toFirstName(string str);

	// Number to character (0 -> A, 1 -> B, 2 -> C, ...)
	static string toCharacter(int nb);

	// Character to number (A -> 0, B -> 1, C -> 2, ...)
	static int toNumber(char character);

	//// Screen ////
	static void clearScreen();
	static void delay(int timeMs);

	//// Text colors ////
	// Set text color, background color, bold and underline styles
	// Colors : {0, 1, 2, 3, 4, 5, 6, 7, 8} : {default, black, red, green, yellow, blue, magenta, cyan, white}
	static string setTextColor(int textColor=0, int backgroundColor=0, bool isBold=false, bool isUnderline=false);

	// Reset text color and styles to default
	static string resetTextColor();

	// Invert text color and background color
	static string invertTextColor();

	// Reset (=remove) text color inversion
	static string resetTextColorInversion();

};


#endif
