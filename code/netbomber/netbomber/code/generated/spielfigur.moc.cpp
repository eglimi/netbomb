/****************************************************************************
** Spielfigur meta object code from reading C++ file 'spielfigur.h'
**
** Created: Thu Jun 27 19:34:02 2002
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.1   edited 2001-04-23 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "spielfigur.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *Spielfigur::className() const
{
    return "Spielfigur";
}

QMetaObject *Spielfigur::metaObj = 0;

void Spielfigur::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("Spielfigur","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString Spielfigur::tr(const char* s)
{
    return qApp->translate( "Spielfigur", s, 0 );
}

QString Spielfigur::tr(const char* s, const char * c)
{
    return qApp->translate( "Spielfigur", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* Spielfigur::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (Spielfigur::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    m1_t0 v1_0 = &Spielfigur::timerDone;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "timerDone()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"Spielfigur", "QObject",
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}
