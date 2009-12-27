/***************************************************************************
                          spieloptview.h  -  description
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

#ifndef SPIELOPIVIEW_H
#define SPIELOPIVIEW_H
#include "generated/gspieloptionen.h"

class SpielView;

class SpielOpiView : public ggameoptions
{ 
    Q_OBJECT

public:
    SpielOpiView( SpielView* spielview,
                  QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~SpielOpiView();

public slots:
    void bApplyPressed();
    void bCancelPressed();

private:
    SpielView* _spielview;

};

#endif // SPIELOPIVIEW_H
