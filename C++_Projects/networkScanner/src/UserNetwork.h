#ifndef _USER_NETWORK_H
#define _USER_NETWORK_H

////////////////////////////////////////////////////////////////////////////////
// HEAD
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <SFML/Network.hpp>
#include "pcapplusplus/PcapLiveDeviceList.h"
#include "pcapplusplus/PlatformSpecificUtils.h"

#include "utils.h"

using namespace std;



////////////////////////////////////////////////////////////////////////////////
// CLASS
class UserNetwork {

	//////////////////////////////
	// MEMBERS
	private:

	string iPv4Address;
	string macAddress;
	string domainName;
	vector<int> portOpen;
	//////////////////////////////
	// PUBLIC METHODS
	public:

	/*####****************** CONSTRUCTOR ******************####*/
	UserNetwork(string ip, string mac="", string dn="");

	/*%%%%------------------ GET INFOS ------------------%%%%*/

	/*####****************** GET IP ******************####*/
	string getIp() const;
	/*####****************** GET MAC ******************####*/
	string getMac() const;
	/*####****************** GET DN ******************####*/
	string getDn() const;
	/*####****************** GET PORT OPEN ******************####*/
	int getPort() const;
    /*####****************** GET PORT OPEN ******************####*/
    vector<int> tabPort() const;

	/*%%%%------------------ CHANGES INFOS ------------------%%%%*/

	/*####****************** CHANGE IP ******************####*/
	void setIp(string ip);
	/*####****************** CHANGE MAC ******************####*/
	void setMac(string mac);
	/*####****************** CHANGE DN ******************####*/
	void setDn(string dn);
	/*####****************** ADD PORT OPEN IN TAB ******************####*/
	void addPort(int port);
	
	/*####****************** SCAN PORT OF THIS HOST ******************####*/
	void scan(int portMin=0, int portMax=1023);

	/*####****************** THREAD USED TO SCAN PORT OF A HOST ******************####*/
	static void threadScan(void *user, int portMin, int portMax);

	/*####****************** SCAN A SPECIFIC PORT OF THIS HOST ******************####*/
	bool scanPort(int &port);
};

#endif