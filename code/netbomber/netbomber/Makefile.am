####### kdevelop will overwrite this part!!! (begin)##########
bin_PROGRAMS = netbomber
netbomber_SOURCES = main.cpp 
SOURCES = ui/generated/gspieloptionen.moc.cpp ui/generated/gspieloptionen.cpp ui/generated/gserverview.moc.cpp ui/generated/gserverview.cpp ui/generated/gjoinserverview.moc.cpp ui/generated/gjoinserverview.cpp network/reactor/playerhandler.cpp network/reactor/reactor.cpp network/reactor/gamehandler.cpp network/reactor/demuxtable.cpp network/reactor/connectionacceptor.cpp network/stringconverter.cpp network/serverinterface.cpp network/networkmanager.cpp network/client.cpp network/clientinterface.cpp pd/serverthread.cpp pd/spielmanager.cpp pd/pdkontroller.cpp pd/bombe.cpp pd/wand.cpp pd/mauer.cpp pd/spielelement.cpp pd/spielfeld.cpp pd/spielfigur.cpp pd/spielfeldclient.cpp pd/spielerclient.cpp pd/spiel.cpp pd/guitopdinterface.cpp ui/playerlistview.cpp ui/emptyview.cpp ui/spieloptview.cpp ui/serverview.cpp ui/joinserverview.cpp ui/flammenview.moc.cpp ui/flammenview.cpp ui/bombenview.cpp ui/wandview.cpp ui/spielview.cpp ui/spielfigurview.cpp ui/spielfeldview.cpp ui/pdtoguiinterface.cpp ui/mauerview.cpp ui/abstractspielelement.cpp main.cpp 
INTERFACES = 
TRANSLATIONS = 
KDE_OPTIONS = qtonly
netbomber_LDADD   = ./ui/libui.a ./pd/libpd.a ./network/libnetwork.a ./network/reactor/libreactor.a ./ui/generated/libgenerated.a  $(LIB_QT) -lXext -lX11 $(LIBSOCKET)

SUBDIRS = ui pd network 

EXTRA_DIST = lo32-app-netbomber.png lo16-app-netbomber.png filenew.xpm filesave.xpm fileopen.xpm main.cpp global.h 

####### kdevelop will overwrite this part!!! (end)############


# set the include path for X, qt and KDE
INCLUDES= $(all_includes)

netbomber_METASOURCES = AUTO

# the library search path. 
netbomber_LDFLAGS = $(all_libraries) 

# them while "make clean", use CLEANFILES
DISTCLEANFILES = $(netbomber_METASOURCES)

# this is to enable Qt behavoir of am_edit
KDE_OPTIONS = qtonly



