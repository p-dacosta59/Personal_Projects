/*
  main.cpp
 
  Created by Pierre Da Costa on 2021/01/09.
  Copyright © 2020 Pierre Da Costa. All rights reserved.
*/
////////////////////////////////////////////////////////////////////////////////
// HEAD
#include "mainWindow.h"
#include <QApplication>


////////////////////////////////////////////////////////////////////////////////
// BODY
int main(int argc, char *argv[]){
    // Begin
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // End
    return a.exec();
}
