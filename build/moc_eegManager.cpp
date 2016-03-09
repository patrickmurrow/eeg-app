/****************************************************************************
** Meta object code from reading C++ file 'eegManager.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/util/eeg/eegManager.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eegManager.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EEGManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      26,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   11,   11,   11, 0x0a,
      68,   11,   11,   11, 0x0a,
     107,   89,   11,   11, 0x0a,
     155,  131,   11,   11, 0x0a,
     202,  180,   11,   11, 0x0a,
     258,  239,   11,   11, 0x0a,
     281,   11,   11,   11, 0x0a,
     288,   11,   11,   11, 0x0a,
     295,   11,   11,   11, 0x0a,
     314,   11,   11,   11, 0x0a,
     336,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EEGManager[] = {
    "EEGManager\0\0dataUpdated()\0sampleReceived(int)\0"
    "startDataCollection()\0stopDataCollection()\0"
    "newX,newY,channel\0updateData(int,int,int)\0"
    "startPos,endPos,channel\0"
    "deleteRange(int,int,int)\0data,startPos,channel\0"
    "insertRange(QList<eegDatum>,int,int)\0"
    "startValue,channel\0updateXValues(int,int)\0"
    "undo()\0redo()\0changeNotch(char*)\0"
    "changeBandpass(char*)\0resetData()\0"
};

void EEGManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EEGManager *_t = static_cast<EEGManager *>(_o);
        switch (_id) {
        case 0: _t->dataUpdated(); break;
        case 1: _t->sampleReceived((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->startDataCollection(); break;
        case 3: _t->stopDataCollection(); break;
        case 4: _t->updateData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->deleteRange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->insertRange((*reinterpret_cast< QList<eegDatum>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->updateXValues((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->undo(); break;
        case 9: _t->redo(); break;
        case 10: _t->changeNotch((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 11: _t->changeBandpass((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 12: _t->resetData(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EEGManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EEGManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EEGManager,
      qt_meta_data_EEGManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EEGManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EEGManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EEGManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EEGManager))
        return static_cast<void*>(const_cast< EEGManager*>(this));
    return QObject::qt_metacast(_clname);
}

int EEGManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void EEGManager::dataUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void EEGManager::sampleReceived(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
