/****************************************************************************
** SpielElement meta object code from reading C++ file 'spielelement.h'
**
** Created: Thu Jun 27 19:33:58 2002
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.1   edited 2001-04-23 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "spielelement.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *SpielElement::className() const
{
    return "SpielElement";
}

QMetaObject *SpielElement::metaObj = 0;

void SpielElement::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("SpielElement","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString SpielElement::tr(const char* s)
{
    return qApp->translate( "SpielElement", s, 0 );
}

QString SpielElement::tr(const char* s, const char * c)
{
    return qApp->translate( "SpielElement", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* SpielElement::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"SpielElement", "QObject",
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
