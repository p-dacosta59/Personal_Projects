#include "mainWindow.h"
#include "ui_mainWindow.h"
////////////////////////////////////////////////////////////////////////////////
// PUBLIC

// Constructors
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

// Destructors
MainWindow::~MainWindow(){
    delete ui;
}
