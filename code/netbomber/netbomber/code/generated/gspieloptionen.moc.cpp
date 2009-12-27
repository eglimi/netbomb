/****************************************************************************
** ggameoptions meta object code from reading C++ file 'gspieloptionen.h'
**
** Created: Thu Jun 27 19:30:42 2002
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.1   edited 2001-04-23 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "gspieloptionen.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *ggameoptions::className() const
{
    return "ggameoptions";
}

QMetaObject *ggameoptions::metaObj = 0;

void ggameoptions::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("ggameoptions","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString ggameoptions::tr(const char* s)
{
    return qApp->translate( "ggameoptions", s, 0 );
}

QString ggameoptions::tr(const char* s, const char * c)
{
    return qApp->translate( "ggameoptions", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* ggameoptions::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (ggameoptions::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (ggameoptions::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    m1_t0 v1_0 = &ggameoptions::bApplyPressed;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &ggameoptions::bCancelPressed;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    QMetaData *slot_tbl = QMetaObject::new_metadata(2);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(2);
    slot_tbl[0].name = "bApplyPressed()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "bCancelPressed()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"ggameoptions", "QWidget",
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
