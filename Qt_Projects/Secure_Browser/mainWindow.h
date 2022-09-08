#ifndef MAINWINDOW_H
#define MAINWINDOW_H

////////////////////////////////////////////////////////////////////////////////
// HEAD
#include <QMainWindow>
#include "WebScrapping.h"
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { 
    class MainWindow; 
}
QT_END_NAMESPACE

////////////////////////////////////////////////////////////////////////////////
// CLASS
class MainWindow : public QMainWindow{
    Q_OBJECT

    //////////////////////////////
	// PUBLIC METHODS
    public:
    // Constructors
    MainWindow(QWidget *parent = nullptr);

    // Destructor
    ~MainWindow();

    public slots:
    // Go to the site entred by the user
    void goSite(string nameSite = "");
    
    // Search data in the Page displayed
    void searchData();

    //////////////////////////////
	// PRIVATE MEMBERS
    private:
    Ui::MainWindow *ui;
    WebScrapping accesSecurity;
};

#endif // MAINWINDOW_H