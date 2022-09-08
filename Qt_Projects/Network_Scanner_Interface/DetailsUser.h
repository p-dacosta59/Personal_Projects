#ifndef DETAILSUSER_H
#define DETAILSUSER_H

////////////////////////////////////////////////////////////////////////////////
// HEAD
#include <QWidget>
#include "UserNetwork.h"

namespace Ui {
    class DetailsUser;
}


////////////////////////////////////////////////////////////////////////////////
// CLASS
class DetailsUser : public QWidget
{
    Q_OBJECT

	//////////////////////////////
	// PUBLIC METHODS
    public:
	// Constructors
    DetailsUser(UserNetwork* userData);

	// Destructor
    ~DetailsUser();

	//////////////////////////////
	// PUBLIC MEMBERS
    private:
    Ui::DetailsUser *ui;

};

#endif // DETAILSUSER_H
