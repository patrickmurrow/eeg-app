/****************************************************************************
** Meta object code from reading C++ file 'bluetoothManager.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/interface/bluetoothManager.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetoothManager.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BluetoothManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   18,   17,   17, 0x05,
      57,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      77,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BluetoothManager[] = {
    "BluetoothManager\0\0addr,name\0"
    "deviceFound(QString,QString)\0"
    "searchFinishedSig()\0searchFinished()\0"
};

void BluetoothManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BluetoothManager *_t = static_cast<BluetoothManager *>(_o);
        switch (_id) {
        case 0: _t->deviceFound((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->searchFinishedSig(); break;
        case 2: _t->searchFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BluetoothManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BluetoothManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BluetoothManager,
      qt_meta_data_BluetoothManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BluetoothManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BluetoothManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BluetoothManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BluetoothManager))
        return static_cast<void*>(const_cast< BluetoothManager*>(this));
    return QObject::qt_metacast(_clname);
}

int BluetoothManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void BluetoothManager::deviceFound(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BluetoothManager::searchFinishedSig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
