/***************************************************************************
                          spieloptview.cpp  -  description
                             -------------------
    begin                : Wed Apr 24 2002
    copyright            : (C) 2002 by S.Kuenzle
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#include "spieloptview.h"
#include "spielview.h"
#include <qlineedit.h>

/* 
 *  Constructs a SpielOpiView which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
SpielOpiView::SpielOpiView( SpielView* spielview, QWidget* parent,  const char* name, WFlags fl )
    : ggameoptions( parent, name, fl ), _spielview(spielview)
{
}

/*  
 *  Destroys the object and frees any allocated resources
 */
SpielOpiView::~SpielOpiView()
{
    // no need to delete child widgets, Qt does it all for us
}

/* 
 * public slot
 */
void SpielOpiView::bApplyPressed()
{
   QString strName = nameEdit->text();
   const char* charName = strName.latin1();
   _spielview->setPlayername(charName);
   hide();

}
/* 
 * public slot
 */
void SpielOpiView::bCancelPressed()
{
   hide();
}

