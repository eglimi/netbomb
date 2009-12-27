/****************************************************************************
** GPlayerListView meta object code from reading C++ file 'gplayerlistview.h'
**
** Created: Fri Jul 12 11:59:06 2002
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.1   edited 2001-04-23 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "gplayerlistview.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *GPlayerListView::className() const
{
    return "GPlayerListView";
}

QMetaObject *GPlayerListView::metaObj = 0;

void GPlayerListView::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("GPlayerListView","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString GPlayerListView::tr(const char* s)
{
    return qApp->translate( "GPlayerListView", s, 0 );
}

QString GPlayerListView::tr(const char* s, const char * c)
{
    return qApp->translate( "GPlayerListView", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* GPlayerListView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"GPlayerListView", "QWidget",
	0, 0,
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
