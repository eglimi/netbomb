/****************************************************************************
** Form implementation generated from reading ui file '/home/urs/new ui files/playerlistview.ui'
**
** Created: Mon Jul 1 13:00:36 2002
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "gplayerlistview.h"

#include <qgroupbox.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a GPlayerListView which is a child of 'parent', with the
 *  name 'name' and widget flags set to 'f' 
 */
GPlayerListView::GPlayerListView( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "GPlayerListView" );
    resize( 239, 309 ); 
    setCaption( tr( "GPlayerListView" ) );

    GroupBox1 = new QGroupBox( this, "GroupBox1" );
    GroupBox1->setGeometry( QRect( 10, 0, 220, 300 ) ); 
    GroupBox1->setTitle( tr( "Player List" ) );
}

/*  
 *  Destroys the object and frees any allocated resources
 */
GPlayerListView::~GPlayerListView()
{
    // no need to delete child widgets, Qt does it all for us
}



