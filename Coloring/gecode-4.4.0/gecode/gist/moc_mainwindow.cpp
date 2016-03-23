/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.hh'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gecode/gist/mainwindow.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Gecode__Gist__GistMainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      45,   30,   29,   29, 0x09,
      76,   29,   29,   29, 0x09,
      90,   84,   29,   29, 0x09,
     108,   29,   29,   29, 0x29,
     122,   29,   29,   29, 0x09,
     151,   29,   29,   29, 0x09,
     172,   29,   29,   29, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_Gecode__Gist__GistMainWindow[] = {
    "Gecode::Gist::GistMainWindow\0\0"
    "stats,finished\0statusChanged(Statistics,bool)\0"
    "about()\0setup\0preferences(bool)\0"
    "preferences()\0populateInspectorSelection()\0"
    "populateInspectors()\0populateBookmarks()\0"
};

void Gecode::Gist::GistMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GistMainWindow *_t = static_cast<GistMainWindow *>(_o);
        switch (_id) {
        case 0: _t->statusChanged((*reinterpret_cast< const Statistics(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->about(); break;
        case 2: _t->preferences((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->preferences(); break;
        case 4: _t->populateInspectorSelection(); break;
        case 5: _t->populateInspectors(); break;
        case 6: _t->populateBookmarks(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Gecode::Gist::GistMainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Gecode::Gist::GistMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Gecode__Gist__GistMainWindow,
      qt_meta_data_Gecode__Gist__GistMainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Gecode::Gist::GistMainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Gecode::Gist::GistMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Gecode::Gist::GistMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gecode__Gist__GistMainWindow))
        return static_cast<void*>(const_cast< GistMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Gecode::Gist::GistMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
