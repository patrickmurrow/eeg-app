/****************************************************************************
** Meta object code from reading C++ file 'newMarkerPrompt.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/interface/newMarkerPrompt.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newMarkerPrompt.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewMarkerPrompt[] = {

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
      25,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   16,   16,   16, 0x0a,
      66,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NewMarkerPrompt[] = {
    "NewMarkerPrompt\0\0val,pos\0"
    "markerCreated(QString,int)\0okayPressed()\0"
    "cancelPressed()\0"
};

void NewMarkerPrompt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NewMarkerPrompt *_t = static_cast<NewMarkerPrompt *>(_o);
        switch (_id) {
        case 0: _t->markerCreated((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->okayPressed(); break;
        case 2: _t->cancelPressed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NewMarkerPrompt::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NewMarkerPrompt::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NewMarkerPrompt,
      qt_meta_data_NewMarkerPrompt, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewMarkerPrompt::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewMarkerPrompt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewMarkerPrompt::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewMarkerPrompt))
        return static_cast<void*>(const_cast< NewMarkerPrompt*>(this));
    return QWidget::qt_metacast(_clname);
}

int NewMarkerPrompt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void NewMarkerPrompt::markerCreated(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
