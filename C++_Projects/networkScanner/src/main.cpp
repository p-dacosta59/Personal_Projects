/*
  main.cpp
 
  Created by Pierre Da Costa on 2021/01/09.
  Copyright © 2020 Pierre Da Costa. All rights reserved.
*/
////////////////////////////////////////////////////////////////////////////////
// HEAD
#include "ScanNetwork.h"


////////////////////////////////////////////////////////////////////////////////
// BODY
int main(int argc, char* argv[]){
	// Begin
	cout << "[BEGIN]-------------------------------------------" << endl;
	ScanNetwork hello;
	vector<UserNetwork*> table;
	hello.nmap(table);
	for (vector<UserNetwork*>::iterator addr_it = table.begin(); addr_it != table.end(); ++addr_it)
		cout << "host with ip '" << (*addr_it)->getIp() << "' and mac '" <<  (*addr_it)->getMac() << "' and with the dn '" <<  (*addr_it)->getDn() << "' and have '" <<  (*addr_it)->getPort() << "' port open" << endl;
	hello.~ScanNetwork();
	// End
	cout << "[END]---------------------------------------------" << endl;
}