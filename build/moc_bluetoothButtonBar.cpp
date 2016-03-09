/****************************************************************************
** Meta object code from reading C++ file 'bluetoothButtonBar.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/interface/bluetoothButtonBar.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluetoothButtonBar.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BluetoothButtonBar[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      36,   19,   19,   19, 0x05,
      53,   19,   19,   19, 0x05,
      67,   19,   19,   19, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_BluetoothButtonBar[] = {
    "BluetoothButtonBar\0\0searchClicked()\0"
    "connectClicked()\0saveClicked()\0"
    "forgetClicked()\0"
};

void BluetoothButtonBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BluetoothButtonBar *_t = static_cast<BluetoothButtonBar *>(_o);
        switch (_id) {
        case 0: _t->searchClicked(); break;
        case 1: _t->connectClicked(); break;
        case 2: _t->saveClicked(); break;
        case 3: _t->forgetClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData BluetoothButtonBar::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BluetoothButtonBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BluetoothButtonBar,
      qt_meta_data_BluetoothButtonBar, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BluetoothButtonBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BluetoothButtonBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BluetoothButtonBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BluetoothButtonBar))
        return static_cast<void*>(const_cast< BluetoothButtonBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int BluetoothButtonBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void BluetoothButtonBar::searchClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void BluetoothButtonBar::connectClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void BluetoothButtonBar::saveClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void BluetoothButtonBar::forgetClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
