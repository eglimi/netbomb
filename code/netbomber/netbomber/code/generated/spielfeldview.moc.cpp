/****************************************************************************
** SpielFeldView meta object code from reading C++ file 'spielfeldview.h'
**
** Created: Mon Jul 1 13:57:31 2002
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.1   edited 2001-04-23 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "spielfeldview.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *SpielFeldView::className() const
{
    return "SpielFeldView";
}

QMetaObject *SpielFeldView::metaObj = 0;

void SpielFeldView::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QCanvasView::className(), "QCanvasView") != 0 )
	badSuperclassWarning("SpielFeldView","QCanvasView");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString SpielFeldView::tr(const char* s)
{
    return qApp->translate( "SpielFeldView", s, 0 );
}

QString SpielFeldView::tr(const char* s, const char * c)
{
    return qApp->translate( "SpielFeldView", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* SpielFeldView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QCanvasView::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (SpielFeldView::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    m1_t0 v1_0 = &SpielFeldView::timerDone;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "timerDone()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"SpielFeldView", "QCanvasView",
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
