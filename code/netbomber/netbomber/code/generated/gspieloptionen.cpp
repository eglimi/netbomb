/****************************************************************************
** Form implementation generated from reading ui file '/home/skuenzle/netbomber/netbomber/ui/generated/gtastaturpanel.ui'
**
** Created: Thu May 30 19:16:43 2002
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "gspieloptionen.h"

#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a ggameoptions which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
ggameoptions::ggameoptions( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "ggameoptions" );
    resize( 227, 416 ); 
    setCaption( tr( "Spieleinstellungen" ) );

    bCancel = new QPushButton( this, "bCancel" );
    bCancel->setGeometry( QRect( 120, 370, 80, 26 ) ); 
    bCancel->setText( tr( "&Abbrechen" ) );

    bApply = new QPushButton( this, "bApply" );
    bApply->setGeometry( QRect( 30, 370, 80, 26 ) ); 
    bApply->setText( tr( QString::fromUtf8( "&Übernehmen" ) ) );

    GroupBox1 = new QGroupBox( this, "GroupBox1" );
    GroupBox1->setGeometry( QRect( 10, 110, 210, 240 ) ); 
    GroupBox1->setTitle( tr( "Tastaturbelegung" ) );

    TextLabel1 = new QLabel( GroupBox1, "TextLabel1" );
    TextLabel1->setGeometry( QRect( 10, 30, 30, 20 ) ); 
    TextLabel1->setText( tr( "Auf:" ) );

    TextLabel1_2 = new QLabel( GroupBox1, "TextLabel1_2" );
    TextLabel1_2->setGeometry( QRect( 10, 70, 30, 20 ) ); 
    TextLabel1_2->setText( tr( "Ab:" ) );

    TextLabel1_3 = new QLabel( GroupBox1, "TextLabel1_3" );
    TextLabel1_3->setGeometry( QRect( 10, 110, 30, 20 ) ); 
    TextLabel1_3->setText( tr( "Links:" ) );

    TextLabel1_4 = new QLabel( GroupBox1, "TextLabel1_4" );
    TextLabel1_4->setGeometry( QRect( 10, 150, 40, 20 ) ); 
    TextLabel1_4->setText( tr( "Rechts:" ) );

    TextLabel3 = new QLabel( GroupBox1, "TextLabel3" );
    TextLabel3->setGeometry( QRect( 10, 190, 80, 20 ) ); 
    TextLabel3->setText( tr( "Bombe legen:" ) );

    aufEdit = new QLineEdit( GroupBox1, "aufEdit" );
    aufEdit->setGeometry( QRect( 100, 30, 60, 22 ) ); 
    QToolTip::add(  aufEdit, tr( "" ) );

    abEdit = new QLineEdit( GroupBox1, "abEdit" );
    abEdit->setGeometry( QRect( 100, 70, 60, 22 ) ); 

    leftEdit = new QLineEdit( GroupBox1, "leftEdit" );
    leftEdit->setGeometry( QRect( 100, 110, 60, 22 ) ); 

    rightEdit = new QLineEdit( GroupBox1, "rightEdit" );
    rightEdit->setGeometry( QRect( 100, 150, 60, 22 ) ); 

    bombEdit = new QLineEdit( GroupBox1, "bombEdit" );
    bombEdit->setGeometry( QRect( 100, 190, 60, 22 ) ); 

    GroupBox2 = new QGroupBox( this, "GroupBox2" );
    GroupBox2->setGeometry( QRect( 10, 10, 211, 90 ) ); 
    GroupBox2->setTitle( tr( "Allgemeines" ) );

    Spielername = new QLabel( GroupBox2, "Spielername" );
    Spielername->setGeometry( QRect( 20, 20, 70, 20 ) ); 
    Spielername->setText( tr( "Playername" ) );

    nameEdit = new QLineEdit( GroupBox2, "nameEdit" );
    nameEdit->setGeometry( QRect( 20, 40, 170, 22 ) ); 
    QToolTip::add(  nameEdit, tr( "Geben Sie hier Ihren Spielername ein!" ) );

    // signals and slots connections
    connect( bApply, SIGNAL( clicked() ), this, SLOT( bApplyPressed() ) );
    connect( bCancel, SIGNAL( clicked() ), this, SLOT( bCancelPressed() ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
ggameoptions::~ggameoptions()
{
    // no need to delete child widgets, Qt does it all for us
}

void ggameoptions::bApplyPressed()
{
    qWarning( "ggameoptions::bApplyPressed(): Not implemented yet!" );
}

void ggameoptions::bCancelPressed()
{
    qWarning( "ggameoptions::bCancelPressed(): Not implemented yet!" );
}

