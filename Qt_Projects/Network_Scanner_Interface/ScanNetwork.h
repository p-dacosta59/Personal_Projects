#ifndef _SCAN_NETWORK_H
#define _SCAN_NETWORK_H


////////////////////////////////////////////////////////////////////////////////
// HEAD
#include <algorithm>
#include <thread>
#include "Poco/Net/ICMPClient.h"
#include "Poco/Net/DNS.h"
#include "Poco/Net/IPAddress.h"
#include "pcapplusplus/Packet.h"
#include "pcapplusplus/EthLayer.h"
#include "pcapplusplus/ArpLayer.h"
#include "pcapplusplus/DnsLayer.h"
#include "UserNetwork.h"

using namespace std;


////////////////////////////////////////////////////////////////////////////////
// CLASS
class ScanNetwork {

	//////////////////////////////
	// MEMBERS
	private:
	pcpp::PcapLiveDevice* dev;
	Poco::Net::IPAddress addressPrivate;
    sf::IpAddress addressPublic;
	vector<UserNetwork*> *userHost;
	vector<thread> threadPorts;
	
	//////////////////////////////
	// PUBLIC METHODS
	public:
	/*####****************** CONSTRUCTOR ******************####*/
	ScanNetwork();

	/*####****************** NMAP BASE RETURN TAB ******************####*/
    vector<UserNetwork*> nmap( string ipAddress, int time, bool arpPing=true);

	/*####****************** NMAP BASE WITH THE ARGUMENT ******************####*/
    bool nmap(vector<UserNetwork*>&table, string ipAddress, int time, bool arpPing=true);

	/*####****************** BROWSE THE NETWORK ******************####*/
    void browseNetwork(int time, bool arpPing);

	/*####****************** PING WITH ICMP ******************####*/
    bool pingNetwork(string ip, int time);

	/*####****************** PING WITH ARP ******************####*/
	void arpPing(string ip);

	/*####****************** GET THE DN ******************####*/
	string getDn(string ipAddress);

	/*####****************** GET PRIVATE IP ******************####*/
    string chossenIpAddress();

    /*####****************** GET ALL PRIVATE IP ******************####*/
    map<string,string> ipAddressPrivate();

	/*####****************** ADD MEMBER IN THE TAB ******************####*/
	void addMember(string ipAddress, string macAddress="", string dn="");

	/*####****************** RETURN HOST POSITION ******************####*/
	int searchHostInTab(string host);

	/*####****************** WAIT FOR ALL THREAD ******************####*/
	void waitThreads();

	/*####****************** METHOD CALLED WHEN INTERFACE RESEIVE PACKAGE ******************####*/
	static bool onPacketArrivesBlockingMode(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie);

	///////////////////////////////
	// PRIVATE METHODS
	private:
	/*####****************** THREAD TO SCAN NETWORK ******************####*/
    static void threadScanPort(void *mainObject, pcpp::PcapLiveDevice* dev, int time);
};

class FindVecteur{
	public:
		FindVecteur(string &ipUser):user(ipUser)
		{}
		/*####****************** FONCTEUR TO FIND CONTAIN IN A VEVCTOR ******************####*/
		bool operator ()(const UserNetwork *user){
			return (user->getIp() == this->user);
		}
	private:
		string user;
};

#endif
