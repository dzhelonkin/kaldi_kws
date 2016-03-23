/****************************************************************************
** Meta object code from reading C++ file 'textoutput.hh'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gecode/gist/textoutput.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textoutput.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Gecode__Gist__TextOutputI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_Gecode__Gist__TextOutputI[] = {
    "Gecode::Gist::TextOutputI\0\0changeStayOnTop()\0"
};

void Gecode::Gist::TextOutputI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TextOutputI *_t = static_cast<TextOutputI *>(_o);
        switch (_id) {
        case 0: _t->changeStayOnTop(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Gecode::Gist::TextOutputI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Gecode::Gist::TextOutputI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Gecode__Gist__TextOutputI,
      qt_meta_data_Gecode__Gist__TextOutputI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Gecode::Gist::TextOutputI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Gecode::Gist::TextOutputI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Gecode::Gist::TextOutputI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gecode__Gist__TextOutputI))
        return static_cast<void*>(const_cast< TextOutputI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Gecode::Gist::TextOutputI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
