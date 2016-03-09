/****************************************************************************
** Meta object code from reading C++ file 'settingsBluetoothTab.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/interface/settingsBluetoothTab.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingsBluetoothTab.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SettingsBluetoothTab[] = {

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
      22,   21,   21,   21, 0x0a,
      36,   21,   21,   21, 0x0a,
      53,   21,   21,   21, 0x0a,
      73,   21,   21,   21, 0x0a,
      88,   21,   21,   21, 0x0a,
     115,  105,   21,   21, 0x0a,
     149,  144,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SettingsBluetoothTab[] = {
    "SettingsBluetoothTab\0\0beginSearch()\0"
    "searchFinished()\0connectToSelected()\0"
    "saveSelected()\0forgetSelected()\0"
    "addr,name\0deviceFound(QString,QString)\0"
    "item\0deviceSelected(BluetoothItem*)\0"
};

void SettingsBluetoothTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SettingsBluetoothTab *_t = static_cast<SettingsBluetoothTab *>(_o);
        switch (_id) {
        case 0: _t->beginSearch(); break;
        case 1: _t->searchFinished(); break;
        case 2: _t->connectToSelected(); break;
        case 3: _t->saveSelected(); break;
        case 4: _t->forgetSelected(); break;
        case 5: _t->deviceFound((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->deviceSelected((*reinterpret_cast< BluetoothItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SettingsBluetoothTab::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SettingsBluetoothTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SettingsBluetoothTab,
      qt_meta_data_SettingsBluetoothTab, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SettingsBluetoothTab::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SettingsBluetoothTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SettingsBluetoothTab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsBluetoothTab))
        return static_cast<void*>(const_cast< SettingsBluetoothTab*>(this));
    return QWidget::qt_metacast(_clname);
}

int SettingsBluetoothTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
