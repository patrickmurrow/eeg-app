/****************************************************************************
** Meta object code from reading C++ file 'eegdisplaydialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/interface/eeg-app/eegdisplaydialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eegdisplaydialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EEGDisplayDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      35,   17,   17,   17, 0x05,
      55,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      78,   17,   17,   17, 0x08,
     100,   17,   17,   17, 0x08,
     116,   17,   17,   17, 0x08,
     130,   17,   17,   17, 0x08,
     157,  151,   17,   17, 0x08,
     191,  188,   17,   17, 0x08,
     238,  225,   17,   17, 0x08,
     276,  268,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EEGDisplayDialog[] = {
    "EEGDisplayDialog\0\0displayStarted()\0"
    "notchChanged(char*)\0bandpassChanged(char*)\0"
    "on_btnStart_clicked()\0updateDisplay()\0"
    "updateRange()\0on_btnStop_clicked()\0"
    "notch\0on_cmbNotch_activated(QString)\0"
    "bp\0on_cmbBandpass_activated(QString)\0"
    "displayNumIn\0on_cmbChannels_activated(int)\0"
    "speedIn\0on_cmbSpeed_activated(QString)\0"
};

void EEGDisplayDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EEGDisplayDialog *_t = static_cast<EEGDisplayDialog *>(_o);
        switch (_id) {
        case 0: _t->displayStarted(); break;
        case 1: _t->notchChanged((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 2: _t->bandpassChanged((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 3: _t->on_btnStart_clicked(); break;
        case 4: _t->updateDisplay(); break;
        case 5: _t->updateRange(); break;
        case 6: _t->on_btnStop_clicked(); break;
        case 7: _t->on_cmbNotch_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_cmbBandpass_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_cmbChannels_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_cmbSpeed_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EEGDisplayDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EEGDisplayDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EEGDisplayDialog,
      qt_meta_data_EEGDisplayDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EEGDisplayDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EEGDisplayDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EEGDisplayDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EEGDisplayDialog))
        return static_cast<void*>(const_cast< EEGDisplayDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int EEGDisplayDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void EEGDisplayDialog::displayStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void EEGDisplayDialog::notchChanged(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void EEGDisplayDialog::bandpassChanged(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
