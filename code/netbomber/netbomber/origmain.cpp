/***************************************************************************
                          main.cpp  -  description
                             -------------------
    begin                : Wed Apr 24 2002
    copyright            : (C) 2002 by Stefan Kuenzle
 ***************************************************************************/
 #include "./ui/spielview.h"
 #include "./ui/pdtoguiinterface.h"
 #include "pd/spiel.h"


 int main(int argc, char* argv[])
 {
 		QApplication netBombAppli(argc,argv);
 		SpielView* _spielview = new SpielView();
 		_spielview->setGeometry(50,50,600,600);
 		
 		netBombAppli.setMainWidget(_spielview);
 		_spielview->show();
 		
 		return netBombAppli.exec();
 }

