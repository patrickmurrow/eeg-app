/****************************************************************************
** Meta object code from reading C++ file 'displayContainer.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/interface/displayContainer.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'displayContainer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DisplayContainer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   18,   17,   17, 0x0a,
      63,   53,   17,   17, 0x0a,
      86,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DisplayContainer[] = {
    "DisplayContainer\0\0pos1,pos2\0"
    "updateMarkerPos(int,int)\0xVal,yVal\0"
    "updateCurrEEG(int,int)\0mouseFollowerUpdated()\0"
};

void DisplayContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DisplayContainer *_t = static_cast<DisplayContainer *>(_o);
        switch (_id) {
        case 0: _t->updateMarkerPos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->updateCurrEEG((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->mouseFollowerUpdated(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DisplayContainer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DisplayContainer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DisplayContainer,
      qt_meta_data_DisplayContainer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DisplayContainer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DisplayContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DisplayContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DisplayContainer))
        return static_cast<void*>(const_cast< DisplayContainer*>(this));
    return QWidget::qt_metacast(_clname);
}

int DisplayContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
