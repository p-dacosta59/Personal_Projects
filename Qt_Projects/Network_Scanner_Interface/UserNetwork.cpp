#include "UserNetwork.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS

/*####****************** CONSTRUCTOR ******************####*/
UserNetwork::UserNetwork(string ip, string mac, string dn) {
    this-> iPv4Address = ip;
    this->macAddress = mac;
    this->domainName = dn;
}

/*%%%%------------------ GET INFOS ------------------%%%%*/

/*####****************** GET IP ******************####*/
string UserNetwork::getIp() const{
    return this->iPv4Address;
}
/*####****************** GET MAC ******************####*/
string UserNetwork::getMac() const{
    return this->macAddress;
}
/*####****************** GET DN ******************####*/
string UserNetwork::getDn() const{
    return this->domainName;
}
/*####****************** GET NUMBER PORT OPEN ******************####*/
int UserNetwork::getPort() const{
    return this->portOpen.size();
}
/*####****************** GET PORT OPEN ******************####*/
vector<int> UserNetwork::tabPort() const{
    return this->portOpen;
}

/*%%%%------------------ CHANGES INFOS ------------------%%%%*/

/*####****************** CHANGE IP ******************####*/
void UserNetwork::setIp(string ip){
    if(ip != "")
        this->iPv4Address = ip;
}
/*####****************** CHANGE MAC ******************####*/
void UserNetwork::setMac(string mac){
    if(mac != "")
        this->macAddress = mac;
}
/*####****************** CHANGE DN ******************####*/
void UserNetwork::setDn(string dn){
    if(dn != "")
        this->domainName = dn;
}
/*####****************** ADD PORT OPEN IN TAB ******************####*/
void UserNetwork::addPort(int port){
    this->portOpen.push_back(port);
}

/*####****************** SCAN PORT OF THIS HOST ******************####*/
void UserNetwork::scan(int portMin, int portMax) {
    for(int i(portMin); i <= portMax; i++){
        if(this->scanPort(i)){
            this->addPort(i);
        }
    }
}

/*####****************** THREAD USED TO SCAN PORT OF A HOST ******************####*/
void UserNetwork::threadScan(void *user, int portMin, int portMax) {
    UserNetwork * myUser = (UserNetwork*)user;
    myUser->scan(portMin, portMax);
}

/*####****************** SCAN A SPECIFIC PORT OF THIS HOST ******************####*/
bool UserNetwork::scanPort(int &port){
    try
    {
        return (sf::TcpSocket().connect(this->iPv4Address, port, sf::seconds(0.02)) == sf::Socket::Done);
    }
    catch(...)
    {
        return false;
    }
    
}