/****************************************************************************
** Form implementation generated from reading ui file '/home/skuenzle/netbomber/netbomber/ui/generated/gjoinserverpanel.ui'
**
** Created: Mon May 27 18:19:52 2002
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "gjoinserverview.h"

#include <qgroupbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a gjoinserverform which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
gjoinserverform::gjoinserverform( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "gjoinserverform" );
    resize( 274, 173 ); 
    setCaption( tr( "Server anmelden" ) );

    bCancel = new QPushButton( this, "bCancel" );
    bCancel->setGeometry( QRect( 140, 130, 80, 26 ) ); 
    bCancel->setText( tr( "&Abbrechen" ) );

    bAnmelden = new QPushButton( this, "bAnmelden" );
    bAnmelden->setGeometry( QRect( 40, 130, 80, 26 ) ); 
    bAnmelden->setText( tr( "An&melden" ) );

    GroupBox6 = new QGroupBox( this, "GroupBox6" );
    GroupBox6->setGeometry( QRect( 10, 20, 250, 90 ) ); 
    GroupBox6->setTitle( tr( "Einstellungen" ) );

    TextLabel7 = new QLabel( GroupBox6, "TextLabel7" );
    TextLabel7->setGeometry( QRect( 20, 20, 61, 20 ) ); 
    TextLabel7->setText( tr( "IP Adresse" ) );

    IPAdressField = new QLineEdit( GroupBox6, "IPAdressField" );
    IPAdressField->setGeometry( QRect( 20, 40, 140, 22 ) ); 
    QToolTip::add(  IPAdressField, tr( "Geben Sie hier die Adresse des Servers im Format w.x.y.z ein" ) );

    // signals and slots connections
    connect( bCancel, SIGNAL( clicked() ), this, SLOT( bCancelPressed() ) );
    connect( bAnmelden, SIGNAL( clicked() ), this, SLOT( bAnmeldenPressed() ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
gjoinserverform::~gjoinserverform()
{
    // no need to delete child widgets, Qt does it all for us
}

void gjoinserverform::bCancelPressed()
{
    qWarning( "gjoinserverform::bCancelPressed(): Not implemented yet!" );
}

void gjoinserverform::bAnmeldenPressed()
{
    qWarning( "gjoinserverform::bAnmeldenPressed(): Not implemented yet!" );
}

