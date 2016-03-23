/****************************************************************************
** Meta object code from reading C++ file 'qtgist.hh'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gecode/gist/qtgist.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtgist.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Gecode__Gist__Gist[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   20,   19,   19, 0x05,
      53,   19,   19,   19, 0x05,
      76,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      93,   19,   19,   19, 0x08,
     138,  135,   19,   19, 0x08,
     191,   19,   19,   19, 0x08,
     228,   19,   19,   19, 0x08,
     262,   19,   19,   19, 0x08,
     292,   19,   19,   19, 0x08,
     319,   19,   19,   19, 0x08,
     347,  344,   19,   19, 0x08,
     372,  368,   19,   19, 0x08,
     392,   19,   19,   19, 0x08,
     413,   19,   19,   19, 0x08,
     437,   19,   19,   19, 0x08,
     451,  449,   19,   19, 0x08,
     479,  449,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Gecode__Gist__Gist[] = {
    "Gecode::Gist::Gist\0\0,\0"
    "statusChanged(Statistics,bool)\0"
    "solution(const Space*)\0searchFinished()\0"
    "on_canvas_contextMenu(QContextMenuEvent*)\0"
    ",,\0on_canvas_statusChanged(VisualNode*,Statistics,bool)\0"
    "selectDoubleClickInspector(QAction*)\0"
    "selectSolutionInspector(QAction*)\0"
    "selectMoveInspector(QAction*)\0"
    "selectComparator(QAction*)\0"
    "selectBookmark(QAction*)\0id\0"
    "addBookmark(QString)\0idx\0removeBookmark(int)\0"
    "populateInspectors()\0populateBookmarksMenu()\0"
    "showStats()\0a\0inspectWithAction(QAction*)\0"
    "inspectBeforeFPWithAction(QAction*)\0"
};

void Gecode::Gist::Gist::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Gist *_t = static_cast<Gist *>(_o);
        switch (_id) {
        case 0: _t->statusChanged((*reinterpret_cast< const Statistics(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->solution((*reinterpret_cast< const Space*(*)>(_a[1]))); break;
        case 2: _t->searchFinished(); break;
        case 3: _t->on_canvas_contextMenu((*reinterpret_cast< QContextMenuEvent*(*)>(_a[1]))); break;
        case 4: _t->on_canvas_statusChanged((*reinterpret_cast< VisualNode*(*)>(_a[1])),(*reinterpret_cast< const Statistics(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 5: _t->selectDoubleClickInspector((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 6: _t->selectSolutionInspector((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 7: _t->selectMoveInspector((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 8: _t->selectComparator((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 9: _t->selectBookmark((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 10: _t->addBookmark((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->removeBookmark((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->populateInspectors(); break;
        case 13: _t->populateBookmarksMenu(); break;
        case 14: _t->showStats(); break;
        case 15: _t->inspectWithAction((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 16: _t->inspectBeforeFPWithAction((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Gecode::Gist::Gist::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Gecode::Gist::Gist::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Gecode__Gist__Gist,
      qt_meta_data_Gecode__Gist__Gist, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Gecode::Gist::Gist::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Gecode::Gist::Gist::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Gecode::Gist::Gist::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gecode__Gist__Gist))
        return static_cast<void*>(const_cast< Gist*>(this));
    return QWidget::qt_metacast(_clname);
}

int Gecode::Gist::Gist::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void Gecode::Gist::Gist::statusChanged(const Statistics & _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Gecode::Gist::Gist::solution(const Space * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Gecode::Gist::Gist::searchFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
