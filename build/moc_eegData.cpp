/****************************************************************************
** Meta object code from reading C++ file 'eegData.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/util/eeg/eegData.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eegData.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EEGData[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,    9,    8,    8, 0x0a,
      64,   51,    8,    8, 0x0a,
      85,    9,    8,    8, 0x0a,
     123,  111,    8,    8, 0x0a,
     157,  139,    8,    8, 0x0a,
     184,  111,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EEGData[] = {
    "EEGData\0\0data,channel,pos\0"
    "insert(eegDatum,int,int)\0data,channel\0"
    "append(eegDatum,int)\0replace(eegDatum,int,int)\0"
    "channel,pos\0remove(int,int)\0"
    "channel,pos,mText\0setMarker(int,int,QString)\0"
    "removeMarker(int,int)\0"
};

void EEGData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EEGData *_t = static_cast<EEGData *>(_o);
        switch (_id) {
        case 0: _t->insert((*reinterpret_cast< eegDatum(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->append((*reinterpret_cast< eegDatum(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->replace((*reinterpret_cast< eegDatum(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->remove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->setMarker((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->removeMarker((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EEGData::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EEGData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EEGData,
      qt_meta_data_EEGData, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EEGData::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EEGData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EEGData::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EEGData))
        return static_cast<void*>(const_cast< EEGData*>(this));
    return QObject::qt_metacast(_clname);
}

int EEGData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
