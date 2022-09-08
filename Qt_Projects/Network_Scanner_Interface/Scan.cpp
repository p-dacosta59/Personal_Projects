#include "Scan.h"
#include "ui_Scan.h"
////////////////////////////////////////////////////////////////////////////////
// PUBLIC

// Constructors
Scan::Scan(QWidget *parent) : QWidget(parent), ui(new Ui::Scan){
    this->ui->setupUi(this);
    this->ui->label_4->hide();
    this->ui->timeIcmp->hide();
    map<string, string> networkCard(this->scanObject.ipAddressPrivate());
    for(map<string,string>::iterator it = networkCard.begin(); it != networkCard.end(); it++){
        this->ui->listInterface->addItem(QString::fromStdString(it->second + " : " + it->first));
    }
    connect(this->ui->pushButtonScan, SIGNAL(clicked()), this, SLOT(onClickScan()));
    connect(this->ui->listUsers, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onClickUser(QListWidgetItem*)));
}

// Destructors
Scan::~Scan(){
    for (vector<UserNetwork*>::iterator it = this->userHost.begin(); it != this->userHost.end(); ++it)
        delete *it;
    delete this->ui;
    delete w;
}

// Conector to scan network
void Scan::onClickScan(){
    if(this->ui->listInterface->currentItem() != NULL){
        string ipChosen(this->ui->listInterface->currentItem()->text().toStdString());
        ipChosen = ipChosen.substr(ipChosen.find(": ")+2);
         if(this->ui->checkBoxArp->isChecked()){
             scanObject.nmap(this->userHost, ipChosen, this->ui->timeArp->value());
        }else{
             scanObject.nmap(this->userHost, ipChosen, this->ui->timeIcmp->value());
         }
        for (vector<UserNetwork*>::iterator addr_it = this->userHost.begin(); addr_it != this->userHost.end(); ++addr_it)
             this->ui->listUsers->addItem(QString::fromStdString((*addr_it)->getIp() + " : " + (*addr_it)->getDn()));
    }else{
        QMessageBox::critical(this, "Erreur de saisie", "Acune interface électionnés");
    }
}

// Connector button
void Scan::onClickUser(QListWidgetItem* item){
    string ipChosen(item->text().toStdString());
    ipChosen = ipChosen.substr(0, ipChosen.find(" : "));
    vector<UserNetwork*>::iterator it = find_if(this->userHost.begin(), this->userHost.end(), FindVecteur(ipChosen));
    if(it != this->userHost.end()){
        w = new DetailsUser(&*(*it));
        w->show();
    }
}
