/*
  main.cpp
 
  Created by Pierre Da Costa on 2021/01/09.
  Copyright © 2020 Pierre Da Costa. All rights reserved.
*/
////////////////////////////////////////////////////////////////////////////////
// HEAD

#include "WebScrapping.h"
#include "utils.h"

using namespace std;


////////////////////////////////////////////////////////////////////////////////
// BODY
int main() {
	// Begin
	cout << "[BEGIN]-------------------------------------------" << endl;

	WebScrapping hello;
	hello.takeProxies();

	// End
	cout << "[END]---------------------------------------------" << endl;
	return 0;
}