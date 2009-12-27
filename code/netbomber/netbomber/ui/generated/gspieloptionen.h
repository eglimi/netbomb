/****************************************************************************
** Form interface generated from reading ui file '/home/skuenzle/netbomber/netbomber/ui/generated/gtastaturpanel.ui'
**
** Created: Thu May 30 19:15:45 2002
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef GGAMEOPTIONS_H
#define GGAMEOPTIONS_H

#include <qvariant.h>
#include <qwidget.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;

class ggameoptions : public QWidget
{ 
    Q_OBJECT

public:
    ggameoptions( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ggameoptions();

    QPushButton* bCancel;
    QPushButton* bApply;
    QGroupBox* GroupBox1;
    QLabel* TextLabel1;
    QLabel* TextLabel1_2;
    QLabel* TextLabel1_3;
    QLabel* TextLabel1_4;
    QLabel* TextLabel3;
    QLineEdit* aufEdit;
    QLineEdit* abEdit;
    QLineEdit* leftEdit;
    QLineEdit* rightEdit;
    QLineEdit* bombEdit;
    QGroupBox* GroupBox2;
    QLabel* Spielername;
    QLineEdit* nameEdit;

public slots:
    virtual void bApplyPressed();
    virtual void bCancelPressed();

};

#endif // GGAMEOPTIONS_H
