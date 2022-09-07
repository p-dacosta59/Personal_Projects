#ifndef _WEB_SCRAPPING_H
#define _WEB_SCRAPPING_H

////////////////////////////////////////////////////////////////////////////////
// HEAD
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>
#include <utility>
#include <netinet/in.h>
#include <curl/curl.h>
#include "utils.h"
using namespace std;


////////////////////////////////////////////////////////////////////////////////
// CLASS
class WebScrapping {

	//////////////////////////////
	// MEMBERS
	private:
	CURL* curl;
	int positionFile;

	//////////////////////////////
	// PUBLIC METHODS
	public:
	// Constructors
	WebScrapping();
	~WebScrapping();

	// Go to a web site return the HTML of site
	string accessSite(string nameSite, bool postData = false, string searchData = "");
	// Access a web site anonymously using proxy rebound
	string simplyAccessSiteAnonyme(string nameSite, bool postData = false, string searchData = "");

	// Access in a web site using a proxie
    string accessSiteAnonyme(string nameSite, int profondeur = 1, bool secur = false, string searchData = "", int latence = 0);
	
	// Go in a website to get a proxie to use
	bool takeProxies(int i = 64);

	// Cut a string to get a target name
	string cutOutString(string &data);

	// Get a URL in a web page
	string getUrl(string &data, string searchData);

	// Dowloaad a file by a website
	void dowloadFiles(string nameSite, string nameFile);

	// Take my agenda in a website
	void takeAgendas();

	//////////////////////////////
	// PRIVATE METHODS
	private:

};
size_t write_data (void* buffer, size_t size, size_t nmemb, void * userp);

#endif
