/***************************************************************************
                          spielview.h  -  description
                             -------------------
    begin                : Wed Apr 24 2002
    copyright            : (C) 2002 by Stefan Kuenzle
 ***************************************************************************/


#ifndef SPIELVIEW_H
#define SPIELVIEW_H

#include <qwidget.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qapplication.h>
#include <qcanvas.h>

class SpielFeldView;
class Spiel;
class JoinServerView;
class ServerView;
class SpielOpiView;
class GUIToPDInterface;
class PlayerListView;

class SpielView : public QWidget  {
   Q_OBJECT
public: 
	SpielView(QWidget *parent=0, const char *name=0);
	~SpielView();
	SpielFeldView* getSpielfeld() const;
	void setPlayername(const char* name);
	void startServer();
  void joinServer(const char* ip);
	
private slots:
	 void slotGame();
	 void slotStartServer();
	 void slotJoinServer();
	 void slotTastatur();
	
protected:
	void keyPressEvent(QKeyEvent* e);
	void keyReleaseEvent(QKeyEvent* e);

private:
	QMenuBar* _menubar;
	QPopupMenu* _gamemenu;
	QPopupMenu* _networkmenu;
	QPopupMenu* _settingsmenu;
	
	SpielFeldView* _spielfeld;
	QCanvas* _gamecanvas;
	Spiel* _spiel;
	
	JoinServerView* _joinserverview;
	ServerView* _serverview;
	SpielOpiView* _spieloptview;
	GUIToPDInterface* _pdinterface;
  PlayerListView* _playerview;
	
	const char* _player;
};

#endif
