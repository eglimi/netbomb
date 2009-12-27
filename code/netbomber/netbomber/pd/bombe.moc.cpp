/****************************************************************************
** Bombe meta object code from reading C++ file 'bombe.h'
**
** Created: Fri Jul 12 12:02:20 2002
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.1   edited 2001-04-23 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "bombe.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *Bombe::className() const
{
    return "Bombe";
}

QMetaObject *Bombe::metaObj = 0;

void Bombe::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(SpielElement::className(), "SpielElement") != 0 )
	badSuperclassWarning("Bombe","SpielElement");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString Bombe::tr(const char* s)
{
    return qApp->translate( "Bombe", s, 0 );
}

QString Bombe::tr(const char* s, const char * c)
{
    return qApp->translate( "Bombe", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* Bombe::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) SpielElement::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (Bombe::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    m1_t0 v1_0 = &Bombe::timeout;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "timeout()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"Bombe", "SpielElement",
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
