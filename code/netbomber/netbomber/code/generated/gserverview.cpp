/****************************************************************************
** Form implementation generated from reading ui file '/home/skuenzle/netbomber/netbomber/ui/generated/gserverpanel.ui'
**
** Created: Mon May 27 18:28:28 2002
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "gserverview.h"

#include <qgroupbox.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qspinbox.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a gserverform which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
gserverform::gserverform( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "gserverform" );
    resize( 239, 183 ); 
    setCaption( tr( "Server starten" ) );

    bStarten = new QPushButton( this, "bStarten" );
    bStarten->setGeometry( QRect( 30, 140, 80, 26 ) ); 
    bStarten->setText( tr( "&Starten" ) );

    bCancel = new QPushButton( this, "bCancel" );
    bCancel->setGeometry( QRect( 130, 140, 80, 26 ) ); 
    bCancel->setText( tr( "&Abbrechen" ) );

    GroupBox3 = new QGroupBox( this, "GroupBox3" );
    GroupBox3->setGeometry( QRect( 10, 10, 220, 110 ) ); 
    GroupBox3->setTitle( tr( "Server Optionen" ) );

    TextLabel6 = new QLabel( GroupBox3, "TextLabel6" );
    TextLabel6->setGeometry( QRect( 10, 40, 120, 20 ) ); 
    TextLabel6->setText( tr( "Max. Anzahl Spieler:" ) );

    maxAnzahlField = new QSpinBox( GroupBox3, "maxAnzahlField" );
    maxAnzahlField->setGeometry( QRect( 140, 40, 56, 23 ) ); 
    maxAnzahlField->setMaxValue( 4 );
    maxAnzahlField->setMinValue( 2 );
    QToolTip::add(  maxAnzahlField, tr( "Als Server bestimmen Sie die maximale Teilnehmeranzahl" ) );

        // signals and slots connections
    connect( bCancel, SIGNAL( clicked() ), this, SLOT( bCancelPressed() ) );
    connect( bStarten, SIGNAL( clicked() ), this, SLOT( bStartenPressed() ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
gserverform::~gserverform()
{
    // no need to delete child widgets, Qt does it all for us
}

void gserverform::bStartenPressed()
{
}

void gserverform::bCancelPressed()
{
}

