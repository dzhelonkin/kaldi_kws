/****************************************************************************
** Meta object code from reading C++ file 'treecanvas.hh'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gecode/gist/treecanvas.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'treecanvas.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Gecode__Gist__SearcherThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      41,   30,   29,   29, 0x05,
      61,   29,   29,   29, 0x05,
      81,   29,   29,   29, 0x05,
      99,   29,   29,   29, 0x05,
     122,   29,   29,   29, 0x05,
     142,  139,   29,   29, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Gecode__Gist__SearcherThread[] = {
    "Gecode::Gist::SearcherThread\0\0w,h,scale0\0"
    "update(int,int,int)\0statusChanged(bool)\0"
    "scaleChanged(int)\0solution(const Space*)\0"
    "searchFinished()\0n,\0moveToNode(VisualNode*,bool)\0"
};

void Gecode::Gist::SearcherThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SearcherThread *_t = static_cast<SearcherThread *>(_o);
        switch (_id) {
        case 0: _t->update((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->statusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->scaleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->solution((*reinterpret_cast< const Space*(*)>(_a[1]))); break;
        case 4: _t->searchFinished(); break;
        case 5: _t->moveToNode((*reinterpret_cast< VisualNode*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Gecode::Gist::SearcherThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Gecode::Gist::SearcherThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Gecode__Gist__SearcherThread,
      qt_meta_data_Gecode__Gist__SearcherThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Gecode::Gist::SearcherThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Gecode::Gist::SearcherThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Gecode::Gist::SearcherThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gecode__Gist__SearcherThread))
        return static_cast<void*>(const_cast< SearcherThread*>(this));
    return QThread::qt_metacast(_clname);
}

int Gecode::Gist::SearcherThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Gecode::Gist::SearcherThread::update(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Gecode::Gist::SearcherThread::statusChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Gecode::Gist::SearcherThread::scaleChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Gecode::Gist::SearcherThread::solution(const Space * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Gecode::Gist::SearcherThread::searchFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Gecode::Gist::SearcherThread::moveToNode(VisualNode * _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
static const uint qt_meta_data_Gecode__Gist__TreeCanvas[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      70,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x05,
      44,   25,   25,   25, 0x05,
      66,   25,   25,   25, 0x05,
     101,   98,   25,   25, 0x05,
     144,   25,   25,   25, 0x05,
     167,   25,   25,   25, 0x05,
     187,  184,   25,   25, 0x05,
     214,  210,   25,   25, 0x05,

 // slots: signature, parameters, type, tag, flags
     254,  235,   25,   25, 0x0a,
     290,  277,   25,   25, 0x2a,
     316,  309,   25,   25, 0x2a,
     331,   25,   25,   25, 0x0a,
     343,   25,   25,   25, 0x0a,
     355,   25,   25,   25, 0x0a,
     370,   25,   25,   25, 0x0a,
     383,   25,   25,   25, 0x0a,
     395,   25,   25,   25, 0x0a,
     408,   25,   25,   25, 0x0a,
     420,   25,   25,   25, 0x0a,
     432,   25,   25,   25, 0x0a,
     453,   25,   25,   25, 0x0a,
     461,   25,   25,   25, 0x0a,
     473,   25,   25,   25, 0x0a,
     509,  493,   25,   25, 0x0a,
     542,  538,   25,   25, 0x2a,
     567,   25,   25,   25, 0x2a,
     588,   25,   25,   25, 0x0a,
     606,   25,   25,   25, 0x0a,
     622,   25,   25,   25, 0x0a,
     634,   25,   25,   25, 0x0a,
     647,   25,   25,   25, 0x0a,
     655,   25,   25,   25, 0x0a,
     663,   25,   25,   25, 0x0a,
     673,   25,   25,   25, 0x0a,
     683,   25,   25,   25, 0x0a,
     694,   25,   25,   25, 0x0a,
     709,  704,   25,   25, 0x0a,
     726,   25,   25,   25, 0x2a,
     739,   25,   25,   25, 0x0a,
     752,   25,   25,   25, 0x0a,
     767,   25,   25,   25, 0x0a,
     777,   25,   25,   25, 0x0a,
     791,   25,   25,   25, 0x0a,
     811,   25,   25,   25, 0x0a,
     839,   25,   25,   25, 0x0a,
     867,  859,   25,   25, 0x0a,
     897,  895,   25,   25, 0x0a,
     921,  895,   25,   25, 0x0a,
     944,   25,  939,   25, 0x0a,
     964,   25,  939,   25, 0x0a,
     978,  895,   25,   25, 0x0a,
     998,   25,  939,   25, 0x0a,
    1016, 1014,   25,   25, 0x0a,
    1032, 1014,   25,   25, 0x0a,
    1053,   25,  939,   25, 0x0a,
    1078,  895,   25,   25, 0x0a,
    1107,   25,  939,   25, 0x0a,
    1129,  895,   25,   25, 0x0a,
    1155,   25,   25,   25, 0x0a,
    1171,   25,  939,   25, 0x0a,
    1180,   25,   25,   25, 0x0a,
    1189,   25,   25,   25, 0x0a,
    1209, 1198,   25,   25, 0x0a,
    1251, 1233,   25,   25, 0x0a,
    1300, 1289,   25,   25, 0x2a,
    1335, 1333,   25,   25, 0x2a,
    1363,   25,   25,   25, 0x08,
    1383, 1333,   25,   25, 0x08,
    1412, 1410,   25,   25, 0x08,
    1442, 1014,   25,   25, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Gecode__Gist__TreeCanvas[] = {
    "Gecode::Gist::TreeCanvas\0\0scaleChanged(int)\0"
    "autoZoomChanged(bool)\0"
    "contextMenu(QContextMenuEvent*)\0,,\0"
    "statusChanged(VisualNode*,Statistics,bool)\0"
    "solution(const Space*)\0searchFinished()\0"
    "id\0addedBookmark(QString)\0idx\0"
    "removedBookmark(int)\0scale0,zoomx,zoomy\0"
    "scaleTree(int,int,int)\0scale0,zoomx\0"
    "scaleTree(int,int)\0scale0\0scaleTree(int)\0"
    "searchAll()\0searchOne()\0toggleHidden()\0"
    "hideFailed()\0unhideAll()\0toggleStop()\0"
    "unstopAll()\0exportPDF()\0exportWholeTreePDF()\0"
    "print()\0zoomToFit()\0centerCurrentNode()\0"
    "fix,inspectorNo\0inspectCurrentNode(bool,int)\0"
    "fix\0inspectCurrentNode(bool)\0"
    "inspectCurrentNode()\0inspectBeforeFP()\0"
    "labelBranches()\0labelPath()\0stopSearch()\0"
    "reset()\0navUp()\0navDown()\0navLeft()\0"
    "navRight()\0navRoot()\0back\0navNextSol(bool)\0"
    "navNextSol()\0navPrevSol()\0bookmarkNode()\0"
    "setPath()\0inspectPath()\0startCompareNodes()\0"
    "startCompareNodesBeforeFP()\0"
    "emitStatusChanged()\0c_d,a_d\0"
    "setRecompDistances(int,int)\0b\0"
    "setAutoHideFailed(bool)\0setAutoZoom(bool)\0"
    "bool\0getAutoHideFailed()\0getAutoZoom()\0"
    "setShowCopies(bool)\0getShowCopies()\0"
    "i\0setRefresh(int)\0setRefreshPause(int)\0"
    "getSmoothScrollAndZoom()\0"
    "setSmoothScrollAndZoom(bool)\0"
    "getMoveDuringSearch()\0setMoveDuringSearch(bool)\0"
    "resizeToOuter()\0finish()\0update()\0"
    "scroll()\0w,h,scale0\0layoutDone(int,int,int)\0"
    "n,finished,update\0"
    "setCurrentNode(VisualNode*,bool,bool)\0"
    "n,finished\0setCurrentNode(VisualNode*,bool)\0"
    "n\0setCurrentNode(VisualNode*)\0"
    "statusChanged(bool)\0exportNodePDF(VisualNode*)\0"
    "s\0inspectSolution(const Space*)\0"
    "scroll(int)\0"
};

void Gecode::Gist::TreeCanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TreeCanvas *_t = static_cast<TreeCanvas *>(_o);
        switch (_id) {
        case 0: _t->scaleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->autoZoomChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->contextMenu((*reinterpret_cast< QContextMenuEvent*(*)>(_a[1]))); break;
        case 3: _t->statusChanged((*reinterpret_cast< VisualNode*(*)>(_a[1])),(*reinterpret_cast< const Statistics(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: _t->solution((*reinterpret_cast< const Space*(*)>(_a[1]))); break;
        case 5: _t->searchFinished(); break;
        case 6: _t->addedBookmark((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->removedBookmark((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->scaleTree((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: _t->scaleTree((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->scaleTree((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->searchAll(); break;
        case 12: _t->searchOne(); break;
        case 13: _t->toggleHidden(); break;
        case 14: _t->hideFailed(); break;
        case 15: _t->unhideAll(); break;
        case 16: _t->toggleStop(); break;
        case 17: _t->unstopAll(); break;
        case 18: _t->exportPDF(); break;
        case 19: _t->exportWholeTreePDF(); break;
        case 20: _t->print(); break;
        case 21: _t->zoomToFit(); break;
        case 22: _t->centerCurrentNode(); break;
        case 23: _t->inspectCurrentNode((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 24: _t->inspectCurrentNode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->inspectCurrentNode(); break;
        case 26: _t->inspectBeforeFP(); break;
        case 27: _t->labelBranches(); break;
        case 28: _t->labelPath(); break;
        case 29: _t->stopSearch(); break;
        case 30: _t->reset(); break;
        case 31: _t->navUp(); break;
        case 32: _t->navDown(); break;
        case 33: _t->navLeft(); break;
        case 34: _t->navRight(); break;
        case 35: _t->navRoot(); break;
        case 36: _t->navNextSol((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->navNextSol(); break;
        case 38: _t->navPrevSol(); break;
        case 39: _t->bookmarkNode(); break;
        case 40: _t->setPath(); break;
        case 41: _t->inspectPath(); break;
        case 42: _t->startCompareNodes(); break;
        case 43: _t->startCompareNodesBeforeFP(); break;
        case 44: _t->emitStatusChanged(); break;
        case 45: _t->setRecompDistances((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 46: _t->setAutoHideFailed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 47: _t->setAutoZoom((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 48: { bool _r = _t->getAutoHideFailed();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 49: { bool _r = _t->getAutoZoom();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 50: _t->setShowCopies((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 51: { bool _r = _t->getShowCopies();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 52: _t->setRefresh((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 53: _t->setRefreshPause((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 54: { bool _r = _t->getSmoothScrollAndZoom();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 55: _t->setSmoothScrollAndZoom((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 56: { bool _r = _t->getMoveDuringSearch();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 57: _t->setMoveDuringSearch((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 58: _t->resizeToOuter(); break;
        case 59: { bool _r = _t->finish();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 60: _t->update(); break;
        case 61: _t->scroll(); break;
        case 62: _t->layoutDone((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 63: _t->setCurrentNode((*reinterpret_cast< VisualNode*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 64: _t->setCurrentNode((*reinterpret_cast< VisualNode*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 65: _t->setCurrentNode((*reinterpret_cast< VisualNode*(*)>(_a[1]))); break;
        case 66: _t->statusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 67: _t->exportNodePDF((*reinterpret_cast< VisualNode*(*)>(_a[1]))); break;
        case 68: _t->inspectSolution((*reinterpret_cast< const Space*(*)>(_a[1]))); break;
        case 69: _t->scroll((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Gecode::Gist::TreeCanvas::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Gecode::Gist::TreeCanvas::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Gecode__Gist__TreeCanvas,
      qt_meta_data_Gecode__Gist__TreeCanvas, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Gecode::Gist::TreeCanvas::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Gecode::Gist::TreeCanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Gecode::Gist::TreeCanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gecode__Gist__TreeCanvas))
        return static_cast<void*>(const_cast< TreeCanvas*>(this));
    return QWidget::qt_metacast(_clname);
}

int Gecode::Gist::TreeCanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 70)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 70;
    }
    return _id;
}

// SIGNAL 0
void Gecode::Gist::TreeCanvas::scaleChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Gecode::Gist::TreeCanvas::autoZoomChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Gecode::Gist::TreeCanvas::contextMenu(QContextMenuEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Gecode::Gist::TreeCanvas::statusChanged(VisualNode * _t1, const Statistics & _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Gecode::Gist::TreeCanvas::solution(const Space * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Gecode::Gist::TreeCanvas::searchFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void Gecode::Gist::TreeCanvas::addedBookmark(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Gecode::Gist::TreeCanvas::removedBookmark(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
