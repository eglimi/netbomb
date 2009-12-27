/****************************************************************************
** Form interface generated from reading ui file '/home/skuenzle/netbomber/netbomber/ui/generated/gjoinserverpanel.ui'
**
** Created: Mon May 27 18:17:19 2002
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef GJOINSERVERFORM_H
#define GJOINSERVERFORM_H

#include <qvariant.h>
#include <qwidget.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;

class gjoinserverform : public QWidget
{ 
    Q_OBJECT

public:
    gjoinserverform( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~gjoinserverform();

    QPushButton* bCancel;
    QPushButton* bAnmelden;
    QGroupBox* GroupBox6;
    QLabel* TextLabel7;
    QLineEdit* IPAdressField;

public slots:
    virtual void bCancelPressed();
    virtual void bAnmeldenPressed();

};

#endif // GJOINSERVERFORM_H
