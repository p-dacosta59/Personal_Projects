#include "mainWindow.h"
#include "./ui_mainWindow.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC

// Constructors
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->connexion, SIGNAL(clicked()), this,SLOT(goSite()));
    connect(ui->searchData, SIGNAL(returnPressed()), this, SLOT(searchData()));
    this->accesSecurity.takeProxies();
    ui->PostData->hide();
    ui->postData->hide();

}

// Destructors
MainWindow::~MainWindow()
{
    delete ui;
}

// Go to the site entred by the user
void MainWindow::goSite(string nameSite){
    if ( ui->urlSite->toPlainText().isEmpty()){
        QMessageBox::critical(this, "Erreur", "Veuillez entrer un URL");
        return;
    }
    string qr;
    while(qr == "")
        qr = this->accesSecurity.accessSiteAnonyme(ui->urlSite->toPlainText().toStdString(), ui->nbProxie->value(), ui->secur->isChecked(), ui->postData->toPlainText().toStdString());
    ui->codeHtml->setPlainText(QString::fromStdString(qr));
    ui->codeSite->setHtml(QString::fromStdString(qr));
}

// Search data in the Page displayed
void MainWindow::searchData(){
    if(!ui->searchData->text().isEmpty()){
        QTextCharFormat fmt;
        fmt.setBackground(Qt::yellow);
        cout << "hello";
        string dataToSearch;
        dataToSearch = ui->searchData->text().toStdString();
        string site;
        site = ui->codeSite->placeholderText().toStdString();
        int p = 0;
        QTextCursor cursor(ui->codeHtml->document());
        QTextCursor cursor2(ui->codeSite->document());
        while(site.find(dataToSearch, p) != string::npos){
            p = site.find(dataToSearch, p);
            cursor.setPosition(p, QTextCursor::MoveAnchor);
            cursor.setPosition(dataToSearch.length(), QTextCursor::KeepAnchor);
            cursor.setCharFormat(fmt);
        }
    }
}
