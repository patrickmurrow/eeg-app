/****************************************************************************
** Meta object code from reading C++ file 'eegDisplayWidget.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/interface/eegDisplayWidget.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eegDisplayWidget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EEGDisplayWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   18,   17,   17, 0x05,
      62,   52,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      87,   83,   17,   17, 0x0a,
     111,   17,   17,   17, 0x0a,
     126,   17,   17,   17, 0x0a,
     142,   17,   17,   17, 0x0a,
     163,   17,   17,   17, 0x0a,
     176,   17,   17,   17, 0x0a,
     198,  190,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EEGDisplayWidget[] = {
    "EEGDisplayWidget\0\0pos1,pos2\0"
    "markersUpdated(int,int)\0xVal,yVal\0"
    "currUpdated(int,int)\0pos\0"
    "ShowContextMenu(QPoint)\0createMarker()\0"
    "removeMarkers()\0deleteSelectedData()\0"
    "undoDelete()\0unselectAll()\0val,pos\0"
    "setMarker(QString,int)\0"
};

void EEGDisplayWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EEGDisplayWidget *_t = static_cast<EEGDisplayWidget *>(_o);
        switch (_id) {
        case 0: _t->markersUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->currUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->ShowContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->createMarker(); break;
        case 4: _t->removeMarkers(); break;
        case 5: _t->deleteSelectedData(); break;
        case 6: _t->undoDelete(); break;
        case 7: _t->unselectAll(); break;
        case 8: _t->setMarker((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EEGDisplayWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EEGDisplayWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EEGDisplayWidget,
      qt_meta_data_EEGDisplayWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EEGDisplayWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EEGDisplayWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EEGDisplayWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EEGDisplayWidget))
        return static_cast<void*>(const_cast< EEGDisplayWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int EEGDisplayWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void EEGDisplayWidget::markersUpdated(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EEGDisplayWidget::currUpdated(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
