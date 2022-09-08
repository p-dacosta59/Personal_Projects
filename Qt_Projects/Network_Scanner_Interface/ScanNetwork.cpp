#include "ScanNetwork.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS

/*####****************** CONSTRUCTOR ******************####*/
ScanNetwork::ScanNetwork(){
}

/*####****************** NMAP BASE RETURN TAB ******************####*/
vector<UserNetwork*> ScanNetwork::nmap(string ipAddress, int time, bool arpPing){
    vector<UserNetwork*> tableToReturn;
    this->addressPrivate = Poco::Net::IPAddress(ipAddress);
    this->userHost = &tableToReturn;
    this->browseNetwork(time, arpPing);
    return tableToReturn;
}

/*####****************** NMAP BASE WITH THE ARGUMENT ******************####*/
bool ScanNetwork::nmap(vector<UserNetwork*>&table, string ipAddress, int time, bool arpPing){
    this->addressPrivate = Poco::Net::IPAddress(ipAddress);
    this->userHost = &table;
    this->browseNetwork(time, arpPing);
    return true;
}

/*####****************** BROWSE THE NETWORK ******************####*/
void ScanNetwork::browseNetwork(int time, bool arpPing){
    this->dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(this->addressPrivate.toString());
    this->dev->open();
    // Part to listen network with arp request
    pcpp::ProtoFilter protocolFilter(pcpp::ARP);
    pcpp::AndFilter andFilter;
    andFilter.addFilter(&protocolFilter);
    pcpp::RawPacketVector packetVec;
    thread scanPortThread;
    scanPortThread = thread(ScanNetwork::threadScanPort, this, this->dev, time);
    // Configure Ip To search
    string ip = this->addressPrivate.toString();
    int lastPosition(0);
    for(int i(0); i < 3; i++)
        lastPosition = ip.find("." ,lastPosition) + 1;
    ip = ip.substr(0, lastPosition);
    // If with arping
    if(arpPing){
        for(int i(1); i < 254; i++){
            string ipLoop;
            ipLoop = ip + Utils::toString(i);
            this->arpPing(ipLoop);
        }
    }
    // Or normal ping
    else{
        for(int i(1); i < 254; i++){
            string ipLoop;
            ipLoop = ip + Utils::toString(i);
            if(this->pingNetwork(ipLoop, time))
                this->arpPing(ipLoop);
        }
    }
    scanPortThread.join();
}

/*####****************** PING WITH ARP ******************####*/
void ScanNetwork::arpPing(string ip){
    // create a new Ethernet layer
    pcpp::EthLayer newEthernetLayer(pcpp::MacAddress(this->dev->getMacAddress().toString()), pcpp::MacAddress("ff:ff:ff:ff:ff:ff"));
    // create a new ARP layer
    pcpp::ArpLayer newArpLayer(pcpp::ArpOpcode(0x0001), pcpp::MacAddress(this->dev->getMacAddress().toString()), pcpp::MacAddress("00:00:00:00:00:00"), pcpp::IPv4Address(this->dev->getIPv4Address()), pcpp::IPv4Address(ip));
    pcpp::Packet newPacket(100);
    // Add all the layers we created
    newPacket.addLayer(&newEthernetLayer);
    newPacket.addLayer(&newArpLayer);
    // make packet
    newPacket.computeCalculateFields();
    // Send Packet
    this->dev->sendPacket(&newPacket);
}

/*####****************** PING WITH ICMP ******************####*/
bool ScanNetwork::pingNetwork(string ip, int repeat){
    try
    {
        Poco::Net::ICMPClient scanner(Poco::Net::IPAddress::IPv4);
        if(scanner.pingIPv4(ip, repeat))
            return true;
        return false;
    }
    catch(Poco::Exception& error){
        return false;
    }
}

/*####****************** GET THE DN ******************####*/
string ScanNetwork::getDn(string ipAddress){
    Poco::Net::HostEntry entry;
    try{
        entry = Poco::Net::DNS::hostByAddress(Poco::Net::IPAddress(ipAddress));
        return entry.name();
    }
    catch(Poco::Exception& error){
        return "";
    }
}

/*####****************** GET PRIVATE IP ******************####*/
string ScanNetwork::chossenIpAddress(){
    return this->addressPrivate.toString();
}

/*####****************** GET ALL PRIVATE IP ******************####*/
map<string,string> ScanNetwork::ipAddressPrivate(){
    map<string,string> tableToReturn;
    Poco::Net::HostEntry salut(Poco::Net::DNS::thisHost());
    const Poco::Net::HostEntry::AddressList& addrs = salut.addresses();
    Poco::Net::HostEntry::AddressList::const_iterator addr_it = addrs.begin();
    for (; addr_it != addrs.end(); ++addr_it){
        string addres(addr_it->toString());
        if(addres != "127.0.0.1" && count(addres.begin(), addres.end(), '.') == 3 && tableToReturn.find(addres)  == tableToReturn.end()){
            dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(addres);
            if(dev != NULL)
                tableToReturn[addres] = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(addres)->getName();
        }
    }
    return tableToReturn;
}

/*####****************** ADD MEMBER IN THE TAB ******************####*/
void ScanNetwork::addMember(string ipAddress, string macAddress, string dn){
    int possition(this->searchHostInTab(ipAddress));
    if(dn == "")
        dn = this->getDn(ipAddress);
    if(possition == -1){
        this->userHost->push_back(new UserNetwork(ipAddress, macAddress, dn));
        this->threadPorts.push_back(thread(&UserNetwork::scan, (*this->userHost)[this->userHost->size()-1], 1, 1023));
    }else{
        (*this->userHost)[possition]->setIp(ipAddress);
        (*this->userHost)[possition]->setMac(macAddress);
        (*this->userHost)[possition]->setDn(dn);
    }
}

/*####****************** RETURN HOST POSITION ******************####*/
int ScanNetwork::searchHostInTab(string host){
    vector<UserNetwork*>::iterator it = find_if(this->userHost->begin(), this->userHost->end(), FindVecteur(host));
    if(it != this->userHost->end())
        return (it - this->userHost->begin());
    return -1;
}

/*####****************** WAIT FOR ALL THREAD ******************####*/
void ScanNetwork::waitThreads(){
    vector<thread>::iterator thread = this->threadPorts.begin();
    for (; thread != this->threadPorts.end(); ++thread){
        thread->join();
    }
}

/*####****************** METHOD CALLED WHEN INTERFACE RESEIVE PACKAGE ******************####*/
bool ScanNetwork::onPacketArrivesBlockingMode(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie){
    ScanNetwork* mainObject = (ScanNetwork*)cookie;
    pcpp::Packet parsedPacket(packet);
    pcpp::EthLayer* ethernetLayer = parsedPacket.getLayerOfType<pcpp::EthLayer>();
    pcpp::ArpLayer *arpLayer = parsedPacket.getLayerOfType<pcpp::ArpLayer>();
    if (ethernetLayer != NULL && arpLayer != NULL)
    {
        if(arpLayer->getSenderIpAddr().toString() != mainObject->chossenIpAddress()){
            mainObject->addMember(arpLayer->getSenderIpAddr().toString(), ethernetLayer->getSourceMac().toString());
        }
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
// PRIVATE METHODS

/*####****************** THREAD TO SCAN NETWORK ******************####*/
void ScanNetwork::threadScanPort(void* mainObject, pcpp::PcapLiveDevice* dev, int time){
    ScanNetwork * object = (ScanNetwork*)mainObject;
    dev->startCaptureBlockingMode(onPacketArrivesBlockingMode, object, time);
    object->waitThreads();
}
