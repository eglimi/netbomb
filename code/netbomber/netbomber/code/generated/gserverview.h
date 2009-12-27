/****************************************************************************
** Form interface generated from reading ui file '/home/skuenzle/netbomber/netbomber/ui/generated/gserverpanel.ui'
**
** Created: Mon May 27 18:27:50 2002
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef GSERVERFORM_H
#define GSERVERFORM_H

#include <qvariant.h>
#include <qwidget.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QGroupBox;
class QLabel;
class QPushButton;
class QSpinBox;

class gserverform : public QWidget
{ 
    Q_OBJECT

public:
    gserverform( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~gserverform();

    QPushButton* bStarten;
    QPushButton* bCancel;
    QGroupBox* GroupBox3;
    QLabel* TextLabel6;
    QSpinBox* maxAnzahlField;

public slots:
    virtual void bStartenPressed();
    virtual void bCancelPressed();

};

#endif // GSERVERFORM_H
