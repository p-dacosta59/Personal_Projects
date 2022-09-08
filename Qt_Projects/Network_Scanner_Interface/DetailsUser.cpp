#include "DetailsUser.h"
#include "ui_DetailsUser.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS

// Constructors
DetailsUser::DetailsUser(UserNetwork* userData) : ui(new Ui::DetailsUser){
    ui->setupUi(this);
    this->ui->ipAddresse->setText(QString::fromStdString(userData->getIp()));
    this->ui->macAddresse->setText(QString::fromStdString(userData->getMac()));
    this->ui->domainName->setText(QString::fromStdString(userData->getDn()));
    vector<int> portOpen(userData->tabPort());
    for(vector<int>::iterator it = portOpen.begin(); it != portOpen.end(); it++){
        this->ui->portOpen->moveCursor (QTextCursor::End);
        this->ui->portOpen->insertPlainText(QString::fromStdString(Utils::toString(*it) + "\n"));
    }
}

// Destructors
DetailsUser::~DetailsUser()
{
    delete ui;
}