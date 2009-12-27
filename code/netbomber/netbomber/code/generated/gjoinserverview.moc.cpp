/****************************************************************************
** gjoinserverform meta object code from reading C++ file 'gjoinserverview.h'
**
** Created: Thu Jun 27 19:31:03 2002
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.1   edited 2001-04-23 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "gjoinserverview.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *gjoinserverform::className() const
{
    return "gjoinserverform";
}

QMetaObject *gjoinserverform::metaObj = 0;

void gjoinserverform::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("gjoinserverform","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString gjoinserverform::tr(const char* s)
{
    return qApp->translate( "gjoinserverform", s, 0 );
}

QString gjoinserverform::tr(const char* s, const char * c)
{
    return qApp->translate( "gjoinserverform", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* gjoinserverform::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (gjoinserverform::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (gjoinserverform::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    m1_t0 v1_0 = &gjoinserverform::bCancelPressed;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &gjoinserverform::bAnmeldenPressed;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    QMetaData *slot_tbl = QMetaObject::new_metadata(2);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(2);
    slot_tbl[0].name = "bCancelPressed()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "bAnmeldenPressed()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"gjoinserverform", "QWidget",
	slot_tbl, 2,
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
