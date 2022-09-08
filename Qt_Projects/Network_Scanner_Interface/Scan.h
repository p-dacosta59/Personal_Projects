
#ifndef SCAN_H
#define SCAN_H

////////////////////////////////////////////////////////////////////////////////
// HEAD
#include <QWidget>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QMainWindow>

#include "ScanNetwork.h"
#include "DetailsUser.h"


namespace Ui {
    class Scan;
}

////////////////////////////////////////////////////////////////////////////////
// CLASS
class Scan : public QWidget
{
    Q_OBJECT

    //////////////////////////////
	// PUBLIC METHODS
    public:
    // Constructors
    Scan(QWidget *parent = nullptr);
    // Destructor
    ~Scan();    
    
    public slots:
    // Conector to scan network
    void onClickScan();

    // Connector button
    void onClickUser(QListWidgetItem* item);

    //////////////////////////////
	// PRIVATE MEMBERS
    private:
    Ui::Scan *ui;
    ScanNetwork scanObject;
    vector<UserNetwork*> userHost;
    vector<DetailsUser> tabWindows;
    DetailsUser* w;

};

#endif // SCAN_H