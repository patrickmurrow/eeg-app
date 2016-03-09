/****************************************************************************
** Meta object code from reading C++ file 'bluetoothDisplayWidget.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/interface/bluetoothDisplayWidget.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetoothDisplayWidget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BluetoothDisplayWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   24,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
      60,   24,   23,   23, 0x0a,
      95,   23,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BluetoothDisplayWidget[] = {
    "BluetoothDisplayWidget\0\0item\0"
    "deviceSelected(BluetoothItem*)\0"
    "deviceItemSelected(BluetoothItem*)\0"
    "removeAllDevices()\0"
};

void BluetoothDisplayWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BluetoothDisplayWidget *_t = static_cast<BluetoothDisplayWidget *>(_o);
        switch (_id) {
        case 0: _t->deviceSelected((*reinterpret_cast< BluetoothItem*(*)>(_a[1]))); break;
        case 1: _t->deviceItemSelected((*reinterpret_cast< BluetoothItem*(*)>(_a[1]))); break;
        case 2: _t->removeAllDevices(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BluetoothDisplayWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BluetoothDisplayWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BluetoothDisplayWidget,
      qt_meta_data_BluetoothDisplayWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BluetoothDisplayWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BluetoothDisplayWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BluetoothDisplayWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BluetoothDisplayWidget))
        return static_cast<void*>(const_cast< BluetoothDisplayWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BluetoothDisplayWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void BluetoothDisplayWidget::deviceSelected(BluetoothItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
