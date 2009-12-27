/****************************************************************************
** SpielView meta object code from reading C++ file 'spielview.h'
**
** Created: Fri Jul 12 12:01:01 2002
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.1   edited 2001-04-23 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "spielview.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *SpielView::className() const
{
    return "SpielView";
}

QMetaObject *SpielView::metaObj = 0;

void SpielView::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("SpielView","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString SpielView::tr(const char* s)
{
    return qApp->translate( "SpielView", s, 0 );
}

QString SpielView::tr(const char* s, const char * c)
{
    return qApp->translate( "SpielView", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* SpielView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (SpielView::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (SpielView::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    typedef void (SpielView::*m1_t2)();
    typedef void (QObject::*om1_t2)();
    typedef void (SpielView::*m1_t3)();
    typedef void (QObject::*om1_t3)();
    m1_t0 v1_0 = &SpielView::slotGame;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &SpielView::slotStartServer;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &SpielView::slotJoinServer;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    m1_t3 v1_3 = &SpielView::slotTastatur;
    om1_t3 ov1_3 = (om1_t3)v1_3;
    QMetaData *slot_tbl = QMetaObject::new_metadata(4);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(4);
    slot_tbl[0].name = "slotGame()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Private;
    slot_tbl[1].name = "slotStartServer()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Private;
    slot_tbl[2].name = "slotJoinServer()";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Private;
    slot_tbl[3].name = "slotTastatur()";
    slot_tbl[3].ptr = (QMember)ov1_3;
    slot_tbl_access[3] = QMetaData::Private;
    metaObj = QMetaObject::new_metaobject(
	"SpielView", "QWidget",
	slot_tbl, 4,
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
