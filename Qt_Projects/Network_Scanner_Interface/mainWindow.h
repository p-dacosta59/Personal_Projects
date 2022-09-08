#ifndef MAINWINDOW_H
#define MAINWINDOW_H

////////////////////////////////////////////////////////////////////////////////
// HEAD
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

////////////////////////////////////////////////////////////////////////////////
// CLASS
class MainWindow : public QMainWindow{
    Q_OBJECT
    //////////////////////////////
	// PUBLIC METHODS
    public:
    // Constructors
    explicit MainWindow(QWidget *parent = nullptr);
    
    // Destructor
    ~MainWindow();

    //////////////////////////////
	// PRIVATE MEMBERS
    private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H